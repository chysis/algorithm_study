#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int N, M, ans=-1;
int map[51][51];
bool checked[51][51], visited[51][51];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<pair<int, int>, int>> q;
queue<pair<int, int>> landQ;
vector<pair<int, int>> land;

int bfs(){
    int temp=-1;
    
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        
        temp=max(temp, cnt);
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]==0) continue;
            
            q.push({{nx, ny}, cnt+1});
            visited[nx][ny]=true;
        }
    }
    
    return temp;
}

void findLand(){
    while(!landQ.empty()){
        int x=landQ.front().first;
        int y=landQ.front().second;
        landQ.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(checked[nx][ny]) continue;
            if(map[nx][ny]==0) continue;
            
            land.push_back({nx, ny});
            landQ.push({nx, ny});
            checked[nx][ny]=true;
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
            char c;
            cin>>c;
            if(c=='W') map[i][j]=0;
            else map[i][j]=1;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==1 && !checked[i][j]){
                checked[i][j]=true;
                landQ.push({i, j});
                land.push_back({i, j});
                findLand();
                
                // 땅 브루트포스 하면서 최단거리 구하기
                for(auto a: land){
                    q.push({{a.first, a.second}, 0});
                    visited[a.first][a.second]=true;
                    ans=max(ans, bfs());
                    
                    if(land.size()<=ans){
                        q={};
                        memset(visited, false, sizeof(visited));
                        break;
                    }
                    
                    q={};
                    memset(visited, false, sizeof(visited));
                }
                
                landQ={};
                land.clear();
            }
        }
    }
    
    cout<<ans;
}