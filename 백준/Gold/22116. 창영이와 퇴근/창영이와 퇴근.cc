#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF (~0U>>2)
#define pipii pair<int, pair<int, int>> 
using namespace std;

int N, map[1001][1001], dist[1001][1001];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

void print(){
    cout<<"\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

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
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            
            int nDist=max(curDist, abs(map[x][y]-map[nx][ny]));
            if(nDist<dist[nx][ny]){
                dist[nx][ny]=nDist;
                pq.push({nDist, {nx, ny}});
                
                // print();
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    
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
    
    cout<<dist[N-1][N-1];
}