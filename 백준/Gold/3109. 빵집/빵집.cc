#include <iostream>
#include <algorithm>
using namespace std;

int R, C, cnt=0;
int dx[3]={-1, 0, 1};
char map[10001][501];
bool isDone=false, visited[10001][501];

void solve(int x, int y){
    if(y==C-1){
        isDone=true;
        cnt++;
        return;
    }
    
    for(int i=0; i<3; i++){
        if(isDone) break;
        
        int nx=x+dx[i];
        int ny=y+1;
        if(nx<0 || nx>=R) continue;
        if(map[nx][ny]=='x') continue;
        
        if(!visited[nx][ny]){
            visited[nx][ny]=true;
            solve(nx, ny);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<R; i++){
        visited[i][0]=true;
        solve(i, 0);
        isDone=false;
    }
    
    cout<<cnt;
}