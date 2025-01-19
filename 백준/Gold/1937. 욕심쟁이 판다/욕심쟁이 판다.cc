#include <iostream>
#include <algorithm>
using namespace std;

int N, map[501][501], dp[501][501];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int solve(int x, int y){
    if(dp[x][y]!=-1) return dp[x][y];
    int& temp=dp[x][y];
    temp=1;
    
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
        if(map[nx][ny]>map[x][y]){
            temp=max(temp, solve(nx, ny)+1);
        }
    }
    
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            dp[i][j]=-1;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            solve(i, j);
        }
    }
    
    int ans=-1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans=max(ans, dp[i][j]);
        }
    }
    
    cout<<ans;
}