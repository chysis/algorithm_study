#include <bits/stdc++.h>
using namespace std;

int T, W, arr[1001], dp[1001][31][3];

int main()
{
    cin>>T>>W;
    for(int i=1; i<=T; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=T; i++){
        for(int j=0; j<=W; j++){
            if(arr[i]==1){
                if(j%2==0){
                    dp[i][j][1]=max(dp[i][j][1], dp[i-1][j][1]+1);
                    if(j && i>1) dp[i][j][1]=max(dp[i][j][1], dp[i-1][j-1][2]+1);
                }
                
                if(j%2==1){
                    dp[i][j][2]=max(dp[i][j][2], dp[i-1][j][2]);
                    if(j && i>1) dp[i][j][2]=max(dp[i][j][2], dp[i-1][j-1][1]+1);
                }
            } else{
                if(j%2==0){
                    dp[i][j][1]=max(dp[i][j][1], dp[i-1][j][1]);
                    if(j && i>1) dp[i][j][1]=max(dp[i][j][1], dp[i-1][j-1][2]+1);
                }
                
                if(j%2==1){
                    dp[i][j][2]=max(dp[i][j][2], dp[i-1][j][2]+1);
                    if(j && i>1) dp[i][j][2]=max(dp[i][j][2], dp[i-1][j-1][1]+1);
                }
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<=W; i++){
        ans=max({ans, dp[T][i][1], dp[T][i][2]});
    }
    
    cout<<ans;
}