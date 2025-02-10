#include <iostream>

#define MOD 1000000000
using namespace std;

int N, K, dp[301][301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;

    for(int i=1; i<=N; i++){
        dp[0][i]=0;
        dp[1][i]=1;
    }
    
    for(int i=1; i<=K; i++){
        dp[i][0]=1;
    }
    
    for(int i=1; i<=K; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<=j; k++){
                dp[i][j]+=(dp[i-1][k]%MOD);
                dp[i][j]%=MOD;
            }
        }
    }
    
    cout<<(dp[K][N]%MOD);
}