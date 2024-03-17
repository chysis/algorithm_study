#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int ans=1;
int map[21][21];
bool visited[26];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

void solve(int x, int y, int cnt){
    ans=max(ans, cnt);
    
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && nx<R && ny>=0 && ny<C && !visited[map[nx][ny]]){
            visited[map[nx][ny]]=true;
            solve(nx, ny, cnt+1);
            visited[map[nx][ny]]=false;
        }
    }
}

int main()
{
    cin>>R>>C;
    char c;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>c;
            map[i][j]=c-'A';
        }
    }
    visited[map[0][0]]=true;
    solve(0, 0, 1);
    cout<<ans;
}