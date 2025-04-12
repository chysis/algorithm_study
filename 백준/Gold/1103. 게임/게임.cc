#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, dp[51][51];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
char arr[51][51];
bool visited[51][51];

int solve(int x, int y){
    if(x<0 || y<0 || x>=N || y>=M || arr[x][y]=='H') return 0;
    if(visited[x][y]){
        cout<<-1;
        exit(0);
    }
    if(dp[x][y]!=-1) return dp[x][y];
    
    int& temp=dp[x][y];

    visited[x][y]=true;
    for(int i=0; i<4; i++){
        int nx=x+dx[i]*(arr[x][y]-'0');
        int ny=y+dy[i]*(arr[x][y]-'0');
        
        temp=max(temp, solve(nx, ny)+1);
    }
    visited[x][y]=false;
    
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
    }
    
    cout<<solve(0, 0);
}