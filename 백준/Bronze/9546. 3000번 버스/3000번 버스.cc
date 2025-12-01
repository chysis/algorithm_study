#include <bits/stdc++.h>
using namespace std;

int N, K, dp[31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[1]=1;
    for(int i=2; i<=30; i++) dp[i]=dp[i-1]*2+1;
    
    cin>>N;
    while(N--){
        cin>>K;
        cout<<dp[K]<<"\n";
    }
}