#include <iostream>
#include <queue>
using namespace std;

int N, M;
int sx, sy;
char map[3001][3001];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<pair<int, int>, int>> q;
bool visited[3001][3001];

int bfs(){
    while(!q.empty()){
        int curX=q.front().first.first;
        int curY=q.front().first.second;
        int cost=q.front().second;
        q.pop();
        
        if(map[curX][curY]>='3' && map[curX][curY]<='5'){
            return cost;
        }
        
        for(int i=0; i<4; i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            
            if(visited[nx][ny]) continue;
            if(map[nx][ny]=='1') continue;
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            
            visited[nx][ny]=true;
            q.push({{nx, ny}, cost+1});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j]=='2'){
                sx=i; sy=j;
            }
        }
    }
    
    q.push({{sx, sy}, 0});
    visited[sx][sy]=true;
    int ans=bfs();
    if(ans!=-1){
        cout<<"TAK\n"<<ans;
    } else{
        cout<<"NIE";
    }
}