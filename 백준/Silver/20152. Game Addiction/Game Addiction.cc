#include <iostream>

#define ll long long
using namespace std;

ll arr[31][31];
ll dp[31][31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H, N;
    cin>>H>>N;
    
    if(H==N) cout<<1;
    else if(H>N){
        dp[N][N]=1;
        for(int i=N; i<=H; i++){
            for(int j=N; j<=H; j++){
                if(i==N && j==N) continue;
                if(j>i) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        cout<<dp[H][H];
    }
    else{
        dp[H][H]=1;
        for(int i=H; i<=N; i++){
            for(int j=H; j<=N; j++){
                if(i==H && j==H) continue;
                if(j>i) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        cout<<dp[N][N];
    }
}