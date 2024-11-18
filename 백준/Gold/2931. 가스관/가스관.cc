#include <iostream>
#include <queue>
using namespace std;

int R, C, sx, sy, susX, susY;
char map[26][26];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[26][26], dir1, dir2, dir3, dir4;
queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        if(map[x][y]=='|'){
            if(!visited[x-1][y]){
                q.push({x-1, y});
                visited[x-1][y]=true;
            }
            if(!visited[x+1][y]){
                q.push({x+1, y});
                visited[x+1][y]=true;
            }
        } else if(map[x][y]=='-'){
            if(!visited[x][y-1]){
                q.push({x, y-1});
                visited[x][y-1]=true;
            }
            if(!visited[x][y+1]){
                q.push({x, y+1});
                visited[x][y+1]=true;
            }
        } else if(map[x][y]=='+'){
            if(!visited[x-1][y]){
                q.push({x-1, y});
                visited[x-1][y]=true;
            }
            if(!visited[x+1][y]){
                q.push({x+1, y});
                visited[x+1][y]=true;
            }
            if(!visited[x][y-1]){
                q.push({x, y-1});
                visited[x][y-1]=true;
            }
            if(!visited[x][y+1]){
                q.push({x, y+1});
                visited[x][y+1]=true;
            }
        } else if(map[x][y]=='1'){
            if(!visited[x+1][y]){
                q.push({x+1, y});
                visited[x+1][y]=true;
            }
            if(!visited[x][y+1]){
                q.push({x, y+1});
                visited[x][y+1]=true;
            }
        } else if(map[x][y]=='2'){
            if(!visited[x-1][y]){
                q.push({x-1, y});
                visited[x-1][y]=true;
            }
            if(!visited[x][y+1]){
                q.push({x, y+1});
                visited[x][y+1]=true;
            }
        } else if(map[x][y]=='3'){
            if(!visited[x][y-1]){
                q.push({x, y-1});
                visited[x][y-1]=true;
            }
            if(!visited[x-1][y]){
                q.push({x-1, y});
                visited[x-1][y]=true;
            }
        } else if(map[x][y]=='4'){
            if(!visited[x][y-1]){
                q.push({x, y-1});
                visited[x][y-1]=true;
            }
            if(!visited[x+1][y]){
                q.push({x+1, y});
                visited[x+1][y]=true;
            }
        } else if(map[x][y]=='.'){
            susX=x, susY=y;
            
            for(int i=0; i<4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(map[nx][ny]!='.' && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny]=true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>R>>C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin>>map[i][j];
            if(map[i][j]=='M'){
                sx=i, sy=j;
            }
        }
    }
    
    // M에서 뻗어나간 파이프 조사
    for(int i=0; i<4; i++){
        int nx=sx+dx[i];
        int ny=sy+dy[i];
        if(map[nx][ny]=='.') continue;
        
        q.push({nx, ny});
        visited[sx][sy]=visited[nx][ny]=true;
    }
    
    bfs();
    
    cout<<susX<<" "<<susY<<" ";
    
    if(map[susX-1][susY]=='|' || map[susX-1][susY]=='+' || map[susX-1][susY]=='1' || map[susX-1][susY]=='4'){
        dir1=true;
    }
    if(map[susX+1][susY]=='|' || map[susX+1][susY]=='+' || map[susX+1][susY]=='2' || map[susX+1][susY]=='3'){
        dir2=true;
    }
    if(map[susX][susY-1]=='-' || map[susX][susY-1]=='+' || map[susX][susY-1]=='1' || map[susX][susY-1]=='2'){
        dir3=true;
    }
    if(map[susX][susY+1]=='-' || map[susX][susY+1]=='+' || map[susX][susY+1]=='3' || map[susX][susY+1]=='4'){
        dir4=true;
    }
    
    if(dir1 && dir2 && !dir3 && !dir4) cout<<"|";
    else if(!dir1 && !dir2 && dir3 && dir4) cout<<"-";
    else if(dir1 && dir2 && dir3 && dir4) cout<<"+";
    else if(!dir1 && dir2 && !dir3 && dir4) cout<<"1";
    else if(dir1 && !dir2 && !dir3 && dir4) cout<<"2";
    else if(dir1 && !dir2 && dir3 && !dir4) cout<<"3";
    else if(!dir1 && dir2 && dir3 && !dir4) cout<<"4";
}