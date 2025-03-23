#include <bits/stdc++.h>
#define MOD 9901 
using namespace std;

int N, dp[100001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    dp[1][0]=dp[1][1]=dp[1][2]=1;
    for(int i=2; i<=N; i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1])%MOD;
    }
    
    cout<<(dp[N][0]+dp[N][1]+dp[N][2])%MOD;
}