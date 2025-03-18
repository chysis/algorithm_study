#include <bits/stdc++.h>
using namespace std;

int N, U, V, dp[1000001]; // dp[i]: i번 노드의 얼리 어답터 여부
vector<int> adj[1000001];
bool visited[1000001];

void solve(int cur){
    visited[cur]=true;
    
    for(auto it: adj[cur]){
        if(visited[it]) continue;
        
        solve(it);
        dp[cur]=max(1-dp[it], dp[cur]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N-1; i++){
        cin>>U>>V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    
    solve(1);
    
    int ans=0;
    for(int i=1; i<=N; i++){
        if(dp[i]) ans++;
    }
    cout<<ans;
}