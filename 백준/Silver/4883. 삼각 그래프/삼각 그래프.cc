#include <iostream>
using namespace std;

int N;
int arr[100001][3], dp[100001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int cnt=1;
    while(true){
        cin>>N;
        if(N==0) break;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<3; j++){
                cin>>arr[i][j];
            }
        }
        
        dp[0][1]=arr[0][1];
        dp[0][2]=arr[0][1]+arr[0][2];
        
        dp[1][0]=arr[0][1]+arr[1][0];
        dp[1][1]=min(min(dp[0][1], dp[0][2]), dp[1][0])+arr[1][1];
        dp[1][2]=min(min(dp[0][1], dp[0][2]), dp[1][1])+arr[1][2];
        
        for(int i=2; i<N; i++){
            dp[i][0]=min(dp[i-1][0], dp[i-1][1])+arr[i][0];
            dp[i][1]=min(min(dp[i][0], dp[i-1][0]), min(dp[i-1][1], dp[i-1][2]))+arr[i][1];
            dp[i][2]=min(min(dp[i-1][1], dp[i-1][2]), dp[i][1])+arr[i][2];
        }
        
        cout<<cnt<<". "<<dp[N-1][1]<<"\n";
        cnt++;
    }
}