#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, P, C, cost[100001], dp[100001]; // dp[i] = i번째 노드를 방문했을 때 써있는 수의 최댓값
vector<ll> adj[100001];

ll solve(int parent, int cur){
    dp[cur]=(parent==-1 ? 0 : dp[parent]) + cost[cur];
    
    for(auto it: adj[cur]){
        dp[cur]=max(dp[cur], solve(cur, it));
    }
    
    return dp[cur];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N-1; i++){
        cin>>P>>C;
        adj[P].push_back(C);
    }
    
    for(int i=0; i<N; i++){
        cin>>cost[i];
    }

    cout<<solve(-1, 0);
}