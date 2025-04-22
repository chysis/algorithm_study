#include <bits/stdc++.h>
using namespace std;

int N, D, A, B, C, dp[10001];
vector<pair<int, int>> adj[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>D;
    for(int i=1; i<=N; i++){
        cin>>A>>B>>C;
        adj[A].push_back({B, C});
    }
    
    for(int i=0; i<=D; i++){
        dp[i]=i;
    }
    
    for(int i=0; i<=D; i++){
        if(i>0) dp[i]=min(dp[i], dp[i-1]+1);
        
        for(int j=0; j<adj[i].size(); j++){
            if(adj[i][j].first>D) continue;
            dp[adj[i][j].first]=min(dp[adj[i][j].first], dp[i]+adj[i][j].second);
        }
    }

    cout<<dp[D];
}