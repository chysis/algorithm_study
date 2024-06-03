#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N,M;
int ice[301][301];
int near[301][301];
bool visited[301][301];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int cnt=0;

queue<pair<int, int>> q;

bool noIce(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(ice[i][j]!=0)
                return false;
        }
    }
    return true;
}

void countZero(){
    memset(near, 0, sizeof(near));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int temp=0;
            for(int k=0; k<4; k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && ni<N && nj>=0 && nj<M && ice[ni][nj]==0){
                    temp++;
                }
            }
            near[i][j]=temp;
        }
    }
}

void iceMelt(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            ice[i][j]-=near[i][j];
            if(ice[i][j]<0) ice[i][j]=0;
        }
    }
}

void dfs(int x, int y){
    visited[x][y]=true;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny] && ice[nx][ny]>0){
            dfs(nx, ny);
        }
    }
}

void bfs(){
    while(!q.empty()){
        int curX=q.front().first;
        int curY=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            
            if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny] && ice[nx][ny]>0){
                q.push({nx, ny});
                visited[nx][ny]=true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>ice[i][j];
        }
    }
    
    int t=0;
    while(true){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!visited[i][j] && ice[i][j]>0){
                    q.push({i, j});
                    // dfs(i, j);
                    bfs();
                    cnt++;
                }
            }
        }
        if(noIce()) {t=0; break;}
        if(cnt>=2) break;
        t++;
        countZero();
        iceMelt();
        cnt=0;
        memset(visited, false, sizeof(visited));
    }
    cout<<t;
}