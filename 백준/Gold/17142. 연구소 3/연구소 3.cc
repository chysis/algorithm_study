#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321
using namespace std;

int N, M, ans=INF;
int map[51][51];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int virusTemp[11];
bool used[11];
bool visited[51][51];

vector<pair<int, int>> virus;
queue<pair<pair<int, int>, int>> q;

int bfs(){
    memset(visited, false, sizeof(visited));
    q={};
    
    int copyMap[51][51];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copyMap[i][j]=map[i][j];
        }
    }
    
    for(int i=0; i<M; i++){
        copyMap[virus[virusTemp[i]].first][virus[virusTemp[i]].second]=10;
        visited[virus[virusTemp[i]].first][virus[virusTemp[i]].second]=true;
        q.push({{virus[virusTemp[i]].first, virus[virusTemp[i]].second}, 10});
    }
    
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=cur.first.first+dx[i];
            int ny=cur.first.second+dy[i];
            int cnt=cur.second;
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if(visited[nx][ny]) continue;
            
            if(copyMap[nx][ny]==0){
                visited[nx][ny]=true;
                copyMap[nx][ny]=cnt+1;
                q.push({{nx, ny}, cnt+1});
            }
            else if(copyMap[nx][ny]==2){
                visited[nx][ny]=true;
                q.push({{nx, ny}, cnt+1});
            }
        }
    }
    
    int tempAns=-1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(copyMap[i][j]==0) return -1;
            else if(copyMap[i][j]>=10){
                tempAns=max(tempAns, copyMap[i][j]);
            }
        }
    }
    
    if(tempAns>=10) return tempAns-10;
    else return tempAns;
}

void solve(int cnt, int idx){
    if(cnt==M){
        int temp=bfs();
        if(temp!=-1){
            ans=min(ans, temp);
        }
        
        return;
    }
    
    for(int i=idx; i<virus.size(); i++){
        if(!used[i]){
            used[i]=true;
            virusTemp[cnt]=i;
            solve(cnt+1, i);
            used[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                virus.push_back({i, j});
            }
        }
    }
    
    solve(0, 0);
    if(ans!=INF) cout<<ans;
    else cout<<-1;
}