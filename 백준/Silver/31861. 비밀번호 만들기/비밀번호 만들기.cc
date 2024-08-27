#include <iostream>

#define MOD 1000000007
using namespace std;

int dp[27][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    
    for(int i=1; i<=26; i++){
        dp[i][1]=1;
    }
    
    for(int i=2; i<=M; i++){
        for(int j=1; j<=26; j++){
            for(int k=1; k<=26; k++){
                if(abs(j-k)>=N){
                    dp[j][i]=(dp[j][i]+dp[k][i-1])%MOD;
                }
            }
        }
    }
    
    int ans=0;
    for(int i=1; i<=26; i++){
        ans=(ans+dp[i][M])%MOD;
    }
    
    cout<<ans;
}