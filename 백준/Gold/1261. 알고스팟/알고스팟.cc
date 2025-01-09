#include <iostream>
#include <queue>
#include <vector>

#define INF (~0U>>2)
#define pipii pair<int, pair<int, int>>
using namespace std;

int N, M, map[101][101], dist[101][101];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

void solve(){
    dist[0][0]=0;
    pq.push({0, {0, 0}});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        
        if(curDist>dist[x][y]) continue;
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            
            int nextDist=(map[nx][ny]==1 ? curDist+1 : curDist);
            if(nextDist<dist[nx][ny]){
                dist[nx][ny]=nextDist;
                pq.push({nextDist, {nx, ny}});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>M>>N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            dist[i][j]=INF;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin>>c;
            map[i][j]=c-'0';
        }
    }
    
    solve();
    
    cout<<dist[N-1][M-1];
}