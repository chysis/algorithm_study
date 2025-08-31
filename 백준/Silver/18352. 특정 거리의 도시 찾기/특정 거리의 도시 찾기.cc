#include <bits/stdc++.h>
using namespace std;

int N, M, K, X, A, B, dist[300001];
vector<int> ans, adj[300001];
queue<pair<int, int>> q;
bool visited[300001];

void solve(){
    while(!q.empty()){
        int cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(cnt==K){
            ans.push_back(cur);
        } else{
            for(auto next: adj[cur]){
                if(visited[next]) continue;
                q.push({next, cnt+1});
                visited[next]=true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K>>X;
    for(int i=0; i<M; i++){
        cin>>A>>B;
        adj[A].push_back(B);
    }
    
    q.push({X, 0});
    visited[X]=true;
    solve();
    
    if(ans.size()==0) cout<<-1;
    else{
        sort(ans.begin(), ans.end());
        for(auto a: ans) cout<<a<<"\n";
    }
}