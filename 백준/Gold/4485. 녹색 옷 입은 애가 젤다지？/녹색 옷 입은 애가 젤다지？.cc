#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define pipii pair<int, pair<int, int>>
#define INF (~0U>>2)
using namespace std;

int N, map[126][126], dist[126][126];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

void solve(){
    dist[0][0]=map[0][0];
    pq.push({map[0][0], {0, 0}});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        
        if(dist[x][y]<curDist) continue;
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            
            int nextDist=curDist+map[nx][ny];
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
    
    int cnt=1;
    while(cin>>N){
        if(N==0) break;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dist[i][j]=INF;
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
            }
        }
        
        solve();

        cout<<"Problem "<<cnt<<": "<<dist[N-1][N-1]<<"\n";
        pq={};
        cnt++;
    }
}