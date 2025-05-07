#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, arr[1001][1001], dp[1001][1001][3]; // dp[i][j][d]: d방향으로 (i, j)까지 갔을 때 최대 가치
bool visited[1001][1001];
int dx[3]={1, 0, 0};
int dy[3]={0, -1, 1};

int solve(int x, int y, int d){
    if(dp[x][y][d]!=-INF) return dp[x][y][d];
    if(x==N && y==M) return arr[x][y];
    
    int& res=dp[x][y][d];

    visited[x][y]=true;
    for(int i=0; i<3; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1 || ny<1 || nx>N || ny>M) continue;
        
        if(visited[nx][ny]) continue;
        res=max(res, solve(nx, ny, i)+arr[x][y]);
    }
    visited[x][y]=false;
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
            dp[i][j][0]=-INF;
            dp[i][j][1]=-INF;
            dp[i][j][2]=-INF;
        }
    }

    cout<<solve(1, 1, 0);
}