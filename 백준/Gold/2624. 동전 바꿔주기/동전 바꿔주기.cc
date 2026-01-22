#include <bits/stdc++.h>
using namespace std;

int T, K, P, N, dp[101][10001];
pair<int, int> arr[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T>>K;
    for(int i=1; i<=K; i++){
        cin>>P>>N;
        arr[i]={P, N};
    }
    
    dp[0][0]=1;
    for(int i=1; i<=T; i++) dp[0][i]=0;
    
    for(int i=1; i<=K; i++){
        for(int j=0; j<=T; j++){
            dp[i][j]=0;
            for(int k=0; k<=arr[i].second; k++){
                if(j-arr[i].first*k>=0){
                    dp[i][j]+=dp[i-1][j-arr[i].first*k];
                }
            }
        }
    }
    
    cout<<dp[K][T];
}