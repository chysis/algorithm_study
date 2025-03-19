#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, U, V, dp[100001][2]; 
vector<int> adj[100001];
bool visited[100001];

void solve(int cur){
    visited[cur]=true;
    
    dp[cur][0]=0;
    dp[cur][1]=1;
    
    for(auto it: adj[cur]){
        if(visited[it]) continue;
        
        solve(it);
        dp[cur][1]+=min(dp[it][0], dp[it][1]);
        dp[cur][0]+=dp[it][1];
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
    cout<<min(dp[1][0], dp[1][1]);
}