#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, arr[301][301], sum[301][301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }
    
    int ans=-INF;
    for(int K=1; K<=N; K++){
        for(int i=1; i<=N-K+1; i++){
            for(int j=1; j<=N-K+1; j++){
                ans=max(ans, sum[i+K-1][j+K-1]-sum[i+K-1][j-1]-sum[i-1][j+K-1]+sum[i-1][j-1]);
            }
        }
    }
    cout<<ans;
}