#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int C, N, dp[21][1101];
pair<int, int> arr[21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>C>>N;
    
    for(int i=0; i<=N; i++){
        for(int j=0; j<=C+100; j++){
            dp[i][j]=INF;
        }
    }
    
    for(int i=1; i<=N; i++){
        int A, B;
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    for(int i=1; i<=N; i++){
        dp[i][arr[i].second]=arr[i].first;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=C+100; j++){
            if(j-arr[i].second>0) dp[i][j]=min({dp[i-1][j], arr[i].first+dp[i-1][j-arr[i].second], arr[i].first+dp[i][j-arr[i].second]});
            else dp[i][j]=min(dp[i][j], dp[i-1][j]);
        }
    }
    
    int ans=INF;
    for(int i=C; i<=C+100; i++){
        ans=min(ans, dp[N][i]);
    }
    
    cout<<ans;
}