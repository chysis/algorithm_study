#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K, zone=1, zoneMap[101][101], sizeMap[10001];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool map[101][101], visited[101][101];
queue<pair<int, int>> q;

void solve(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1 || ny<1 || nx>N || ny>M) continue;
            if(visited[nx][ny]) continue;
            if(!map[nx][ny]) continue;
            
            q.push({nx, ny});
            visited[nx][ny]=true;
            zoneMap[nx][ny]=zone;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        int R, C;
        cin>>R>>C;
        map[R][C]=true;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(!visited[i][j] && map[i][j]){
                visited[i][j]=true;
                zoneMap[i][j]=zone;
                q.push({i, j});
                solve();
                
                zone++;
                q={};
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            sizeMap[zoneMap[i][j]]++;
        }
    }
    
    int ans=0;
    for(int i=1; i<=N*M; i++){
        ans=max(ans, sizeMap[i]);
    }
    
    cout<<ans;
}