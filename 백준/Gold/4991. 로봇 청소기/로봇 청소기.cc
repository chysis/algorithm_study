#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>
using namespace std;

int W, H;
int sx, sy, ansBit, bit;
char map[21][21];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[21][21][1025];
queue<tuple<int, int, int, int>> q;

int bfs(){
    while(!q.empty()){
        int curX=get<0>(q.front());
        int curY=get<1>(q.front());
        int cnt=get<2>(q.front());
        int bit=get<3>(q.front());
        q.pop();
        
        if(bit==ansBit){
            return cnt;
        }
        
        for(int i=0; i<4; i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            int nB=bit;
            
            if(nx<0 || ny<0 || nx>=H || ny>=W) continue;
            
            if(0<=map[nx][ny]-'0' && map[nx][ny]-'0'<=9){
                nB|=(1<<(map[nx][ny]-'0'));
                
                if(!visited[nx][ny][nB]){
                    visited[nx][ny][nB]=true;
                    q.push({nx, ny, cnt+1, nB});
                }
            } else if(map[nx][ny]!='x' && !visited[nx][ny][nB]){
                visited[nx][ny][nB]=true;
                q.push({nx, ny, cnt+1, nB});
            }
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        cin>>W>>H;
        if(W==0 && H==0) break;
        
        int cnt=0;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin>>map[i][j];
                if(map[i][j]=='o'){
                    sx=i, sy=j;
                } else if(map[i][j]=='*'){
                    map[i][j]=(cnt++)+'0';
                }
            }
        }
        
        ansBit=(1<<cnt)-1;
        
        q.push({sx, sy, 0, 0});
        visited[sx][sy][0]=true;
        
        cout<<bfs()<<"\n";
        
        q={};
        memset(visited, false, sizeof(visited));
    }
}