#include <iostream>
#include <queue>
#include <tuple>

#define ti5 tuple<int, int, int, int, int>
using namespace std;

int N, M;
int ax, ay, bx, by;
char map[21][21];
bool visited[21][21][21][21];
int dx[9]={0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9]={0, 0, 1, 1, 1, 0, -1, -1, -1};
queue<ti5> q;

int bfs(){
    while(!q.empty()){
        int curAx=get<0>(q.front());
        int curAy=get<1>(q.front());
        int curBx=get<2>(q.front());
        int curBy=get<3>(q.front());
        int cnt=get<4>(q.front());
        q.pop();
        
        if(curAx==bx && curAy==by && curBx==ax && curBy==ay){
            return cnt;
        }
        
        for(int i=0; i<9; i++){
            int nAx=curAx+dx[i];
            int nAy=curAy+dy[i];
            
            if(map[nAx][nAy]=='X') continue;
            if(nAx<0 || nAy<0 || nAx>=N || nAy>=M) continue;
            
            for(int j=0; j<9; j++){
                int nBx=curBx+dx[j];
                int nBy=curBy+dy[j];
                
                if(map[nBx][nBy]=='X') continue;
                if(visited[nAx][nAy][nBx][nBy]) continue;
                if(nAx==curBx && nAy==curBy && curAx==nBx && curAy==nBy) continue;
                if(nAx==nBx && nAy==nBy) continue;
                if(nBx<0 || nBy<0 || nBx>=N || nBy>=M) continue;
                
                visited[nAx][nAy][nBx][nBy]=true;
                q.push({nAx, nAy, nBx, nBy, cnt+1});
            }
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j]=='A'){
                ax=i, ay=j;
            } else if(map[i][j]=='B'){
                bx=i, by=j;
            }
        }
    }
    
    q.push({ax, ay, bx, by, 0});
    visited[ax][ay][bx][by]=true;
    
    cout<<bfs();
}