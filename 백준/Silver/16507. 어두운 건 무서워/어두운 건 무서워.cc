#include <bits/stdc++.h>
using namespace std;

int R, C, Q, r1, r2, c1, c2, arr[1001][1001], sum[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C>>Q;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }
    
    for(int i=0; i<Q; i++){
        cin>>r1>>c1>>r2>>c2;
        cout<<(sum[r2][c2]-sum[r1-1][c2]-sum[r2][c1-1]+sum[r1-1][c1-1])/((r2-r1+1)*(c2-c1+1))<<"\n";
    }
}