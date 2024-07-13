#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
char map[101][101];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

queue<pair<int, int>> tempQ;
bool tempVisited[101][101];
bool visited[101][101];

void bfs(){
    while(!tempQ.empty()){
        int cx=tempQ.front().first;
        int cy=tempQ.front().second;
        tempQ.pop();
        
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(tempVisited[nx][ny]) continue;
            if(map[nx][ny]=='0') continue;
            
            tempQ.push({nx, ny});
            tempVisited[nx][ny]=true;
        }
    }
}

bool isOneMold(){
    memset(tempVisited, false, sizeof(tempVisited));
    int cnt=0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]!='0' && !tempVisited[i][j]){
                cnt++;
                tempVisited[i][j]=true;
                tempQ.push({i, j});
                bfs();
            }
        }
    }
    
    if(cnt==1) return true;
    return false;
}

void spread(){
    char tempMap[101][101];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tempMap[i][j]=map[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]!='0'){
                int speed=map[i][j]-'0';
                
                for(int x=i-speed; x<=i+speed; x++){
                    for(int y=j-speed; y<=j+speed; y++){
                        if(x<0 || y<0 || x>=N || y>=M) continue;
                        tempMap[x][y]=max(map[x][y]-'0', speed)+'0';
                    }
                }
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map[i][j]=tempMap[i][j];
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
    
    int day=0;
    while(true){
        if(isOneMold()){
            cout<<day;
            break;
        }
        
        day++;
        spread();
    }
}