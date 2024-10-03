#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int N, M;
int arr[1001][1001], dp[1001][1001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<3; k++){
                dp[i][j][k]=INF;
            }
        }
    }
    
    for(int i=0; i<M; i++){
        if(i==0){
            dp[1][i][1]=arr[0][i]+arr[1][i];
            dp[1][i][2]=arr[0][i+1]+arr[1][i];
        } else if(i==M-1){
            dp[1][i][0]=arr[0][i-1]+arr[1][i];
            dp[1][i][1]=arr[0][i]+arr[1][i];
        } else{
            dp[1][i][0]=arr[0][i-1]+arr[1][i];
            dp[1][i][1]=arr[0][i]+arr[1][i];
            dp[1][i][2]=arr[0][i+1]+arr[1][i];
        }
    }
    
    for(int i=2; i<N; i++){
        for(int j=0; j<M; j++){
            if(j==0){
                dp[i][j][1]=dp[i-1][j][2]+arr[i][j];
                dp[i][j][2]=min(dp[i-1][j+1][0], dp[i-1][j+1][1])+arr[i][j];
            } else if(j==M-1){
                dp[i][j][0]=min(dp[i-1][j-1][1], dp[i-1][j-1][2])+arr[i][j];
                dp[i][j][1]=dp[i-1][j][0]+arr[i][j];
            } else {
                dp[i][j][0]=min(dp[i-1][j-1][1], dp[i-1][j-1][2])+arr[i][j];
                dp[i][j][1]=min(dp[i-1][j][0], dp[i-1][j][2])+arr[i][j];
                dp[i][j][2]=min(dp[i-1][j+1][0], dp[i-1][j+1][1])+arr[i][j];
            }
        }
    }
    
    int ans=INF;
    for(int i=0; i<M; i++){
        for(int j=0; j<3; j++){
            ans=min(ans, dp[N-1][i][j]);
        }
    }
    
    cout<<ans;
}