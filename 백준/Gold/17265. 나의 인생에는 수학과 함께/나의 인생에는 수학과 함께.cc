#include <iostream>
#include <algorithm>
#define INF (~0U>>2)
using namespace std;

int N, minAns[6][6], maxAns[6][6];
int dx[2]={1, 0};
int dy[2]={0, 1};
char map[6][6];

void solve(int x, int y, int prev){
    if(map[x][y]>='0' && map[x][y]<='5'){
        maxAns[x][y]=max(maxAns[x][y], prev);
        minAns[x][y]=min(minAns[x][y], prev);
    }
    
    for(int i=0; i<2; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
        if(map[nx][ny]>='0' && map[nx][ny]<='5'){
            int num;
            if(map[x][y]=='+') num=prev+(map[nx][ny]-'0');
            else if(map[x][y]=='-') num=prev-(map[nx][ny]-'0');
            else if(map[x][y]=='*') num=prev*(map[nx][ny]-'0');
            
            if(maxAns[nx][ny]<num || minAns[nx][ny]>num){
                solve(nx, ny, num);
            }
        } else{
            solve(nx, ny, prev);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            minAns[i][j]=INF;
            maxAns[i][j]=-INF;
        }
    }
    
    minAns[0][0]=map[0][0]-'0';
    maxAns[0][0]=map[0][0]-'0';
    solve(0, 0, map[0][0]-'0');
    
    cout<<maxAns[N-1][N-1]<<" "<<minAns[N-1][N-1];
}