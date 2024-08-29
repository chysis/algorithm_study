#include <iostream>

#define INF 1000000001
using namespace std;

int M, N;
int map[501][501];
int dp[501][501];
bool visited[501][501];

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int solve(int x, int y){
    if(x==M && y==N){
        return 1;
    }
    
    if(visited[x][y]) return dp[x][y];
    
    visited[x][y]=true;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1 && ny>=1 && nx<=M && ny<=N && map[nx][ny]<map[x][y]){
            dp[x][y]+=solve(nx, ny);
        }
    }
    
    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>M>>N;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
        }
    }
    
    cout<<solve(1, 1);
}