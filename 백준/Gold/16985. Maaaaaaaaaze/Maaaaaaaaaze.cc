#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <memory.h>

#define INF 987654321
using namespace std;

int res=INF;
bool used[5];
pair<int, int> ans[5];
int counter[5][5][5];
bool visited[5][5][5];
int maze[5][5][5];
int stages[5][5][5];
int dx[6]={-1, 1, 0, 0, 0, 0};
int dy[6]={0, 0, -1, 1, 0, 0};
int dz[6]={0, 0, 0, 0, -1, 1};

int bfs(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                counter[i][j][k]=0;
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0]=true;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        if(cur==make_tuple(4, 4, 4)){
            return counter[get<0>(cur)][get<1>(cur)][get<2>(cur)];
        }
        
        for(int i=0; i<6; i++){
            int nz=get<0>(cur)+dz[i];
            int nx=get<1>(cur)+dx[i];
            int ny=get<2>(cur)+dy[i];
            if(maze[nz][nx][ny]==1 && !visited[nz][nx][ny] && nx>=0 && ny>=0 && nz>=0 && nx<5 && ny<5 && nz<5){
                q.push({nz, nx, ny});
                visited[nz][nx][ny]=true;
                counter[nz][nx][ny]=counter[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            }
        }
    }
    return -1;
}

void makeMaze(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                maze[i][j][k]=stages[ans[i].first][j][k];
            }
        }
    }
    
    int temp[5][5];
    for(int i=0; i<5; i++){
        int a=ans[i].second;
        while(a--){
            for(int j=0; j<5; j++){
                for(int k=0; k<5; k++){
                    temp[k][5-j-1]=maze[i][j][k];
                }
            }
            for(int j=0; j<5; j++){
                for(int k=0; k<5; k++){
                    maze[i][j][k]=temp[j][k];
                }
            }
        }
    }
}

void solve(int cnt){
    if(cnt==5){
        makeMaze();
        if(maze[0][0][0]!=1 || maze[4][4][4]!=1) return;
        int temp=bfs();
        if(temp!=-1) res=min(res, temp);
        return;
    }
    
    for(int i=0; i<5; i++){
        if(!used[i]){
            used[i]=true;
            for(int j=0; j<4; j++){
                ans[cnt]={i, j};
                solve(cnt+1);
            }
            used[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                cin>>stages[i][j][k];
            }
        }
    }

    solve(0);
    
    if(res==INF) cout<<-1;
    else cout<<res;
}