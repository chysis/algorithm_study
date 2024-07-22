#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>

#define INF 987654321
using namespace std;

int N, M;
int map[51][51];
int dist[51][51];
bool visited[51][51];
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
queue<tuple<int, int, int>> q;

int solve(){
    int ans=-1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(dist[i][j]==INF) continue;
            ans=max(ans, dist[i][j]);
        }
    }
    
    return ans;
}

void bfs(){
    while(!q.empty()){
        int cx=get<0>(q.front());
        int cy=get<1>(q.front());
        int cnt=get<2>(q.front());
        q.pop();
        
        for(int i=0; i<8; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]==1) continue;
            
            dist[nx][ny]=min(dist[nx][ny], cnt+1);
            q.push({nx, ny, cnt+1});
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
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            dist[i][j]=INF;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==1){
                q.push({i, j, 0});
                bfs();
                memset(visited, false, sizeof(visited));
            }
        }
    }
    
    cout<<solve();
}