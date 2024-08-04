#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, maxHeight=-1, ans=0;
int map[101][71];
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
bool visited[101][71];

vector<pair<int, int>> v;
queue<pair<int, int>> q;

bool isPeak(int height){
    for(auto a: v){
        int x=a.first;
        int y=a.second;
        
        for(int i=0; i<8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(map[nx][ny]>height) return false;
        }
    }
    
    return true;
}

void bfs(int height){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]!=height) continue; 
            
            q.push({nx, ny});
            visited[nx][ny]=true;
            v.push_back({nx, ny});
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
            maxHeight=max(maxHeight, map[i][j]);
        }
    }
    
    for(int h=1; h<=maxHeight; h++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j]==h && !visited[i][j]){
                    q.push({i, j});
                    visited[i][j]=true;
                    v.push_back({i, j});
                    bfs(h);
                    if(isPeak(h)) ans++;
                    
                    v.clear();
                }
            }
        }
    }
    
    cout<<ans;
}