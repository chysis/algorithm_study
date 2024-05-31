#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
int ans, remain;

int map[101][101];
bool deleteMap[101][101];

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[101][101];
queue<pair<int, int>> q;

int countCheese(){
    int temp=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==1) temp++;
        }
    }
    
    return temp;
}

void updateMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==1 && deleteMap[i][j]){
                map[i][j]=0;
            }
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
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]==1){
                deleteMap[nx][ny]=true;
                visited[nx][ny]=true;
                continue;
            }
            
            q.push({nx, ny});
            visited[nx][ny]=true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    int cnt=0;
    while(true){
        if(countCheese()==0){
            ans=cnt;
            break;
        }
        
        memset(visited, false, sizeof(visited));
        memset(deleteMap, false, sizeof(deleteMap));
        q={};
        
        visited[0][0]=true;
        q.push({0, 0});
        
        bfs();
        remain=countCheese();
        updateMap();
        cnt++;
    }
    
    cout<<ans<<"\n"<<remain;
}