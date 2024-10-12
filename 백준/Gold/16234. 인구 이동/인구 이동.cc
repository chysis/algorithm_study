#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int N, L, R, map[51][51];
bool open[51][51], visited[51][51];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<int, int>> q;
vector<int> v;
vector<pair<int, int>> area;

int newPopulation(){
    int sum=0;
    for(auto a: v){
        sum+=a;
    }
    
    return sum/v.size();
}

bool canMove(){
    // 가로
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            int diff=abs(map[i][j]-map[i][j+1]);
            if(diff>=L && diff<=R){
                return true;
            }
        }
    }
    
    // 세로
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N; j++){
            int diff=abs(map[i][j]-map[i+1][j]);
            if(diff>=L && diff<=R){
                return true;
            }
        }
    }
    
    return false;
}

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int diff=abs(map[x][y]-map[nx][ny]);
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if(diff<L || diff>R) continue;
            if(visited[nx][ny]) continue;
            
            visited[nx][ny]=true;
            q.push({nx, ny});
            v.push_back(map[nx][ny]);
            area.push_back({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>L>>R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    
    int cnt=0;
    while(true){
        memset(open, false, sizeof(open));
        memset(visited, false, sizeof(visited));
        if(!canMove()) break;
        cnt++;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j]){
                    visited[i][j]=true;
                    q.push({i, j});
                    v.push_back(map[i][j]);
                    area.push_back({i, j});
                    bfs();
                    
                    int temp=newPopulation();
                    for(auto a: area){
                        map[a.first][a.second]=temp;
                    }
                    
                    q={};
                    v.clear();
                    area.clear();
                }
            }
        }
    }
    
    cout<<cnt;
}