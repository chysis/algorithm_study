#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

// dp[i][j]: i회차에 무기 j를 골랐을 때 걸리는 시간의 최솟값
int N, M, arr[501][501], dp[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<M; i++) dp[0][i]=arr[0][i];
    
    for(int i=1; i<N; i++){
        for(int j=0; j<M; j++){
            dp[i][j]=INF;
            for(int k=0; k<M; k++){
                if(j==k) continue;
                dp[i][j]=min(dp[i][j], dp[i-1][k]+arr[i][j]);
            }
        }
    }
    
    int ans=INF;
    for(int i=0; i<M; i++){
        ans=min(ans, dp[N-1][i]);
    }
    cout<<ans;
}