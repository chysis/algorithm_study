#include <bits/stdc++.h>
#define INF (~0U>>2)
#define piipii pair<pair<int, int>, pair<int, int>>
using namespace std;

struct comp{
    bool operator()(piipii& a, piipii& b){
        if(a.first.first==b.first.first){
            return a.first.second>b.first.second;
        } else{
            return a.first.first>b.first.first;
        }
    }
};

int N, M, fx, fy;
pair<int, int> dist[51][51]; // [i][j]까지 통과한 쓰레기 개수, 쓰레기 옆 지나간 칸 개수
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
char arr[51][51];
priority_queue<piipii, vector<piipii>, comp> pq;

void solve(){
    while(!pq.empty()){
        int curGarb=pq.top().first.first;
        int curNearGarb=pq.top().first.second;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        
        if(dist[x][y].first<curGarb || 
        (dist[x][y].first==curGarb && dist[x][y].second<curNearGarb)) continue;
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            
            int nextGarb=curGarb, nextNearGarb=curNearGarb;
            if(arr[nx][ny]=='g') nextGarb++;
            else if(arr[nx][ny]=='.'){
                bool isNear=false;
                for(int j=0; j<4; j++){
                    int nnx=nx+dx[j];
                    int nny=ny+dy[j];
                    if(nnx<0 || nny<0 || nnx>=N || nny>=M) continue;
                    if(arr[nnx][nny]=='g'){
                        isNear=true;
                        break;
                    }
                }
                
                if(isNear) nextNearGarb++;
            }
            
            if(dist[nx][ny].first>nextGarb ||
            (dist[nx][ny].first==nextGarb && dist[nx][ny].second>nextNearGarb)){
                dist[nx][ny]={nextGarb, nextNearGarb};
                pq.push({{nextGarb, nextNearGarb}, {nx, ny}});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            dist[i][j]={INF, INF};
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='S'){
                pq.push({{0, 0}, {i, j}});
            } else if(arr[i][j]=='F'){
                fx=i, fy=j;
            }
        }
    }
    
    solve();
    cout<<dist[fx][fy].first<<" "<<dist[fx][fy].second;
}