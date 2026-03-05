#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

// dp[i][j]: i~j번째 행렬 곱을 구하는 데 필요한 최소 연산 횟수
int N, dp[501][501];
pair<int, int> arr[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) dp[i][j]=0;
            else dp[i][j]=INF;
        }
    }
    
    for(int len=2; len<=N; len++){
        for(int i=1; i<=N-len+1; i++){
            int j=i+len-1;
            for(int k=i; k<j; k++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+(arr[i].first*arr[k].second*arr[j].second));
            }
        }
    }
    
    cout<<dp[1][N];
}