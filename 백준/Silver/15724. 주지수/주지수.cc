#include <iostream>
using namespace std;

int N, M, K, x1, y1, x2, y2, arr[1025][1025], dp[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
        }
    }
    
    cin>>K;
    for(int i=0; i<K; i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]<<"\n";
    }
}