#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

#define ti5 tuple<int, int, int, int, int>
#define INF 987654321
using namespace std;

int N, H, D, sx, sy;
char map[501][501];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int visited[501][501];

queue<ti5> q; // x, y, h, um, cnt

int bfs(){
    int ans=INF;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int h=get<2>(q.front());
        int um=get<3>(q.front());
        int cnt=get<4>(q.front());
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nH, nUm;
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if(map[nx][ny]=='E'){
                ans=min(ans, cnt+1);
                continue;
            }
            
            if(map[nx][ny]=='U'){
                nUm=D-1; // 우산 쓰고 비 맞고
                nH=h;
            } else{
                if(um==0){
                    nUm=0;
                    nH=h-1;
                } else {
                    nUm=um-1;
                    nH=h;
                }
            }

            if(nH<=0) continue;
            
            if(visited[nx][ny]<nH+nUm){
                q.push({nx, ny, nH, nUm, cnt+1});
                visited[nx][ny]=nH+nUm;
            }
        }
    }
    
    if(ans==INF) return -1;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>H>>D;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j]=-1;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if(map[i][j]=='S'){
                sx=i, sy=j;
            }
        }
    }
    
    q.push({sx, sy, H, 0, 0});
    visited[sx][sy]=H;
    cout<<bfs();
}