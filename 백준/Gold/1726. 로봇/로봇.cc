#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
int sx, sy, sd, fx, fy, fd;
int map[101][101];
int dx[5]={0, 0, 1, 0, -1};
int dy[5]={0, 1, 0, -1, 0};
bool visited[101][101][5];

queue<tuple<int, int, int, int>> q; // x, y, dir, cnt

int bfs(){
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int dir=get<2>(q.front());
        int cnt=get<3>(q.front());
        q.pop();
        
        if(x==fx && y==fy && dir==fd) return cnt;
        
        for(int i=0; i<5; i++){
            if(x==fx && y==fy && i>0) continue;
            
            if(i==0){
                int nextDir;
                
                // turn left
                nextDir=(dir-1<1)?4:(dir-1);
                if(!visited[x][y][nextDir]){
                    q.push({x, y, nextDir, cnt+1});
                    visited[x][y][nextDir]=true;
                }
                
                // turn right
                nextDir=(dir+1>4)?1:(dir+1);
                if(!visited[x][y][nextDir]){
                    q.push({x, y, nextDir, cnt+1});
                    visited[x][y][nextDir]=true;
                }
            } else{
                int nx, ny;
                
                for(int j=1; j<=3; j++){
                    nx=x+dx[dir]*j;
                    ny=y+dy[dir]*j;
                    
                    bool flag=true;
                    
                    // 여러 칸 뛰는 경우 그 사이에 궤도가 있는지 검사
                    for(int k=1; k<=j-1; k++){
                        int tempX=x+dx[dir]*k;
                        int tempY=y+dy[dir]*k;
                        if(map[tempX][tempY]==1) {
                            flag=false;
                            break;
                        }
                    }
                    
                    if(nx>=1 && ny>=1 && nx<=N && ny<=M && map[nx][ny]==0 && flag && !visited[nx][ny][dir]){
                        q.push({nx, ny, dir, cnt+1});
                        visited[nx][ny][dir]=true;
                    }
                }
            }
        }
    }
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>map[i][j];
        }
    }
    
    cin>>sx>>sy>>sd>>fx>>fy>>fd;
    if(sd==2) sd=3;
    else if(sd==3) sd=2;
    
    if(fd==2) fd=3;
    else if(fd==3) fd=2;
    
    q.push({sx, sy, sd, 0});
    visited[sx][sy][sd]=true;
    cout<<bfs();
}