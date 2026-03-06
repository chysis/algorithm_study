#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

// dp[i][j] : i~j번째 파일을 합치는 데 필요한 최소 비용
int T, K, arr[501], sum[501], dp[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>K;
        for(int i=1; i<=K; i++){
            cin>>arr[i];
            sum[i]=sum[i-1]+arr[i];
        }
        
        // initial value
        for(int i=1; i<=K; i++){
            for(int j=1; j<=K; j++){
                if(i==j) dp[i][j]=0;
                else dp[i][j]=INF;
            }
        }
        
        // len=2일 때 합치는 비용
        for(int i=1; i<=K-1; i++){
            dp[i][i+1]=arr[i]+arr[i+1];
        }
        
        // dp배열을 순서대로 채울 경우 중간에 채워지지 않은 값 참조
        // 따라서 구간의 길이에 따라 채우기
        for(int len=3; len<=K; len++){
            for(int i=1; i<=K-len+1; i++){
                int j=i+len-1;
                for(int k=i; k<j; k++){
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+(sum[j]-sum[i-1]));
                }
            }
        }
        
        cout<<dp[1][K]<<"\n";
    }
}