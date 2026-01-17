#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, arr[201][201], sum[201][201], ans=-INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }
    
    for(int h=0; h<N; h++){
        for(int w=0; w<M; w++){
            for(int i=1; i<=N-h; i++){
                for(int j=1; j<=M-w; j++){
                    int temp=sum[i+h][j+w]-sum[i-1][j+w]-sum[i+h][j-1]+sum[i-1][j-1];
                    ans=max(ans, temp);
                }
            }
        }
    }
    
    cout<<ans;
}