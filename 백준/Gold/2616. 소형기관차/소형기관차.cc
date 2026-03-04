#include <bits/stdc++.h>
using namespace std;

// dp[i][j]: i대 배치하고 j칸까지 봤을 때 얻을 수 있는 최댓값
int N, C, arr[50001], sum[50001], dp[4][50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    cin>>C;
    
    for(int i=0; i<=N; i++) dp[0][i]=0; // 0대 배치
    for(int i=0; i<4; i++) dp[i][0]=0; // 범위 밖
    
    for(int i=1; i<4; i++){
        for(int j=1; j<=N; j++){
            int rangeSum=sum[j]-sum[j-C];
            if(j>=C) dp[i][j]=max(dp[i][j-1], dp[i-1][j-C] + rangeSum);
        }
    }
    
    cout<<dp[3][N];
}