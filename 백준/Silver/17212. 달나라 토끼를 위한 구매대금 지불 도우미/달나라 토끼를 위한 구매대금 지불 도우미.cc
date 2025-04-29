#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, dp[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        dp[i]=INF;
    }
    
    dp[1]=dp[2]=dp[5]=dp[7]=1;
    
    for(int i=1; i<=N; i++){
        if(dp[i]==1) continue;
        
        if(i>=7) dp[i]=min(dp[i], dp[i-7]+1);
        if(i>=5) dp[i]=min(dp[i], dp[i-5]+1);
        if(i>=2) dp[i]=min(dp[i], dp[i-2]+1);
        dp[i]=min(dp[i], dp[i-1]+1);
    }
    
    cout<<dp[N];
}