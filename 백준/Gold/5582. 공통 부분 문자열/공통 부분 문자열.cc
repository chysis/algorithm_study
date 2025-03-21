#include <bits/stdc++.h>
using namespace std;

int dp[4001][4001]; // dp[i][j]: S의 i번째, T의 j번째까지 비교했을 때 가장 긴 공통 부분 문자열 길이
string S, T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S>>T;
    
    for(int i=0; i<=S.length(); i++){
        for(int j=0; j<=T.length(); j++){
            if(i==0 || j==0) dp[i][j]=0; // set margin
            else{
                if(S[i-1]==T[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=0;
            }
        }
    }
    
    int ans=-1;
    for(int i=0; i<=S.length(); i++){
        for(int j=0; j<=T.length(); j++){
            ans=max(ans, dp[i][j]);
        }
    }
    
    cout<<ans;
}