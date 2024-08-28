#include <iostream>

#define MOD 1000000003
using namespace std;

int dp[1001][1001];

int main()
{
    int N, K;
    cin>>N>>K;
    
    for(int i=0; i<=N; i++){
        dp[i][1]=i; // 한 가지 색 고르는 경우
        dp[i][0]=1; // 안 고르는 경우는 1가지
    }
    
    // DP 배열 채우기
    for(int i=2; i<=N; i++){
        for(int j=1; j<=K; j++){
            // 선형으로 생각하고 i번째 선택하는 경우 + 선택하지 않는 경우
            dp[i][j]=(dp[i-2][j-1]+dp[i-1][j])%MOD;
        }
    }
    
    // 원형에서 1/N번째 색이 선택된 경우 + 선택되지 않은 경우
    cout<<(dp[N-3][K-1]+dp[N-1][K])%MOD;
}