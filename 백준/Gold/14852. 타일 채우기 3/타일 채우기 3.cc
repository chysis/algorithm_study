#include <iostream>
#define MOD 1000000007
using namespace std;

int N;
long long dp[1000001], mem[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    dp[1]=2, dp[2]=7;
    mem[1]=dp[1]*2+2;
    mem[2]=dp[2]*2+dp[1]*2+2;
    
    for(int i=3; i<=N; i++){
        dp[i]=(dp[i-1]*2+dp[i-2]+mem[i-2])%MOD;
        mem[i-1]=(mem[i-2]+dp[i-1]*2)%MOD;
    }
    
    cout<<dp[N];
}