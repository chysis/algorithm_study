#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int T, num, dp[100001][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[1][1]=dp[2][2]=1;
    dp[3][1]=dp[3][2]=dp[3][3]=1;
    
    for(int i=4; i<=100000; i++){
        dp[i][1]=(dp[i-1][2]+dp[i-1][3])%MOD;
        dp[i][2]=(dp[i-2][1]+dp[i-2][3])%MOD;
        dp[i][3]=(dp[i-3][1]+dp[i-3][2])%MOD;
    }
    
    cin>>T;
    while(T--){
        cin>>num;
        cout<<((dp[num][1]+dp[num][2])%MOD+dp[num][3])%MOD<<"\n";
    }
}