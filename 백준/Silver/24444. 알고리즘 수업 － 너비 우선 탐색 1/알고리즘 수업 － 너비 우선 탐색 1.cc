#include <bits/stdc++.h>
using namespace std;

int N, M, R, u, v, ord[100001], cnt=1;
vector<int> adj[100001];
queue<int> q;
bool visited[100001];

void solve(int start){
    q.push(start);
    ord[start]=cnt;
    visited[start]=true;
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        for(auto next: adj[cur]){
            if(visited[next]) continue;
            q.push(next);
            cnt++;
            ord[next]=cnt;
            visited[next]=true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>R;
    for(int i=0; i<M; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1; i<=N; i++) sort(adj[i].begin(), adj[i].end());
    
    solve(R);
    
    for(int i=1; i<=N; i++) cout<<ord[i]<<"\n";
}