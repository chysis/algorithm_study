#include <bits/stdc++.h>
using namespace std;

int N, dp[21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    dp[1]=1, dp[2]=2, dp[3]=4, dp[4]=7;
    for(int i=5; i<=N; i++){
        if(i%2==0){
            dp[i]=dp[i-1]*2-dp[i-4]-dp[i-5];
        } else{
            dp[i]=dp[i-1]*2;
        }
    }
    
    cout<<dp[N];
}