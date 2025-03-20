#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, S, M, v[51], dp[51][1001]; // dp[i][j]: i번째 곡까지 연주했을 때 볼륨 j를 만들 수 있는지 여부

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>S>>M;
    
    for(int i=1; i<=N; i++){
        cin>>v[i];
    }
    
    dp[0][S]=1;
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            if(dp[i-1][j]){
                if(j+v[i]<=M) dp[i][j+v[i]]=1;
                if(j-v[i]>=0) dp[i][j-v[i]]=1;
            }
        }
    }
    
    for(int i=M; i>=0; i--){
        if(dp[N][i]){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}