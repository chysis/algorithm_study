#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, dp[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    
    dp[0]=0, dp[1]=1;
    for(int i=2; i<=N; i++){
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    
    cout<<dp[N];
}