#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    while(true){
        cin>>N>>M;
        if(N==0 && M==0) break;
        
        memset(dp, 0, sizeof(dp));
        
        int ans=0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                cin>>arr[i][j];
                if(arr[i][j]==1){
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                    ans=max(ans, dp[i][j]);
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}