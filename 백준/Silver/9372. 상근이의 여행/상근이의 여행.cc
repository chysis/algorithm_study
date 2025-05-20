#include <bits/stdc++.h>
using namespace std;

int T, N, M, A, B;
vector<int> adj[1001];
bool visited[1001];
queue<int> q;

void init(){
    q={};
    memset(visited, false, sizeof(visited));
    for(int i=1; i<=N; i++) adj[i].clear();
}

int solve(){
    q.push(1);
    visited[1]=true;
    int ans=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        for(auto next: adj[cur]){
            if(visited[next]) continue;
            visited[next]=true;
            ans++;
            q.push(next);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=0; i<M; i++){
            cin>>A>>B;
            adj[A].push_back(B);
            adj[B].push_back(A);
        }

        cout<<solve()<<"\n";
        init();
    }
}