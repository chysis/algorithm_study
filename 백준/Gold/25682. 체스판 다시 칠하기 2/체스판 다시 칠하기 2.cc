#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, K, ans=INF, dpB[2001][2001], dpW[2001][2001];
char arr[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
            int extraW, extraB;
            if(arr[i][j]=='B'){
                if((i+j)%2==0) extraB=0;
                else extraB=1;
                extraW=1-extraB;
            } else{
                if((i+j)%2==0) extraW=0;
                else extraW=1;
                extraB=1-extraW;
            }
            
            dpW[i][j]=dpW[i-1][j]+dpW[i][j-1]-dpW[i-1][j-1]+extraW;
            dpB[i][j]=dpB[i-1][j]+dpB[i][j-1]-dpB[i-1][j-1]+extraB;
        }
    }
    
    for(int i=1; i<=N-K+1; i++){
        for(int j=1; j<=M-K+1; j++){
            int b=dpB[i+K-1][j+K-1]-dpB[i-1][j+K-1]-dpB[i+K-1][j-1]+dpB[i-1][j-1];
            int w=dpW[i+K-1][j+K-1]-dpW[i-1][j+K-1]-dpW[i+K-1][j-1]+dpW[i-1][j-1];
            ans=min({ans, b, w});
        }
    }
    
    cout<<ans;
}