#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>

#define INF 987654321
using namespace std;

int N;
int area=0;
int map[101][101];
int areaMap[101][101];
int bridgeCnt[101][101];
bool visited[101][101];

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

queue<pair<int, int>> q;

int minBridge(int curArea){
    int temp=INF;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(areaMap[i][j]>0 && areaMap[i][j]!=curArea){
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    
                    if(nx>=0 && ny>=0 && nx<N && ny<N && bridgeCnt[nx][ny]!=0){
                        temp=min(temp, bridgeCnt[nx][ny]);
                    }
                }
            }
        }
    }
    
    return temp;
}

int bridge(int curArea){
    int temp=INF;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(map[nx][ny]==0 && !visited[nx][ny] && nx>=0 && ny>=0 && nx<N && ny<N){
                visited[nx][ny]=true;
                q.push({nx, ny});
                bridgeCnt[nx][ny]=bridgeCnt[x][y]+1;
            }
        }
    }
    
    return minBridge(curArea);
}

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        areaMap[x][y]=area;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(map[nx][ny]==1 && !visited[nx][ny] && nx>=0 && ny>=0 && nx<N && ny<N){
                visited[nx][ny]=true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==1){
                if(visited[i][j]) continue;
                q.push({i, j});
                area++;
                bfs();
            }
        }
    }
    
    int ans=INF;
    for(int x=1; x<area; x++){
        memset(visited, false, sizeof(visited));
        q={};
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(areaMap[i][j]==x){
                    q.push({i, j});
                }
            }
        }
        ans=min(ans, bridge(x));
    }
    cout<<ans;
}