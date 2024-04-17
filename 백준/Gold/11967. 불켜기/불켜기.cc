#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int ans=1;
bool light[101][101];
bool visited[101][101];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
vector<pair<int, int>> v[101][101];
queue<pair<int, int>> q;

int count(){
    int temp=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(light[i][j] && visited[i][j]) {temp++;}
        }
    }
    return temp;
}

void bfs(){
    while(!q.empty()){
        int curX=q.front().first;
        int curY=q.front().second;
        q.pop();
        
        for(auto a: v[curX][curY]){
            if(visited[a.first][a.second]) continue;
            if(light[a.first][a.second]) continue;
            light[a.first][a.second]=true;
            ans++;
            
            for(int i=0; i<4; i++){
                int nx=a.first+dx[i];
                int ny=a.second+dy[i];
                if(nx>=1 && ny>=1 && nx<=N && ny<=N && visited[nx][ny]){
                    q.push({a.first, a.second});
                    visited[a.first][a.second]=true;
                    break;
                }
            }
        }
        // ans=max(ans, count());
        
        for(int i=0; i<4; i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(nx>=1 && ny>=1 && nx<=N && ny<=N && !visited[nx][ny] && light[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny]=true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        v[x][y].push_back({a, b});
    }
    
    q.push({1, 1});
    visited[1][1]=true;
    light[1][1]=true;
    bfs();
    
    cout<<ans;
}