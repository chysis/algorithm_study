#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[31];

int main()
{
    dp[0]=1, dp[1]=1, dp[2]=2;
    for(int i=3; i<=30; i++){
        for(int j=0; j<i; j++){
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }
    
    while(true){
        cin>>N;
        if(N==0) break;
        
        cout<<dp[N]<<"\n";   
    }
}