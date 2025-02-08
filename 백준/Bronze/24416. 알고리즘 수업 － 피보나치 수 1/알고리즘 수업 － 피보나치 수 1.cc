#include <iostream>
using namespace std;

int N, dp[41];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    dp[1]=dp[2]=1;
    for(int i=3; i<=N; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[N]<<" "<<N-2;
}