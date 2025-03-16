#include <bits/stdc++.h>
using namespace std;

int N, R, Q, U, V, dp[100001]; // dp[i]: i를 루트로 하는 서브트리의 정점 개수
vector<int> adj[100001];
bool visited[100001];

void solve(int cur){
    if(visited[cur]) return;
    visited[cur]=true;
    
    int& temp=dp[cur]=1;
    for(auto it: adj[cur]){
        if(visited[it]) continue;
        solve(it);
        temp+=dp[it];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>R>>Q;
    
    for(int i=0; i<N-1; i++){
        cin>>U>>V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    
    solve(R);
    
    for(int i=0; i<Q; i++){
        cin>>U;
        cout<<dp[U]<<"\n";
    }
}