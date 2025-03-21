#include <bits/stdc++.h>
using namespace std;

int dp[4001][4001];
string S, T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S>>T;
    
    int ans=-1;
    for(int i=0; i<=S.length(); i++){
        for(int j=0; j<=T.length(); j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(S[i-1]==T[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
            
            ans=max(ans, dp[i][j]);
        }
    }
    cout<<ans;
}