#include <iostream>
#include <algorithm>
using namespace std;

int N, M, available[501][501];
char map[501][501];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int solve(int x, int y){
    if(available[x][y]!=-1) return available[x][y];
    
    int& temp=available[x][y];
    temp=0;
    
    int nx, ny;
    if(map[x][y]=='D') nx=x+dx[1], ny=y+dy[1];
    else if(map[x][y]=='U') nx=x+dx[0], ny=y+dy[0];
    else if(map[x][y]=='L') nx=x+dx[2], ny=y+dy[2];
    else if(map[x][y]=='R') nx=x+dx[3], ny=y+dy[3];
    
    if(nx<0 || nx>=N || ny<0 || ny>=M){
        temp=1;
        return temp;
    }
    
    temp=solve(nx, ny);

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            available[i][j]=-1;
        }
    }
    
    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int res=solve(i, j);
            if(res==1) cnt++;
        }
    }
    
    cout<<cnt;
}