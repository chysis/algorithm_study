#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int W, H, map[51][51], ans=0;
bool visited[51][51];
int dx[8]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8]={0, 0, -1, 1, -1, 1, -1, 1};
queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=H || ny>=W) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]==0) continue;
            
            q.push({nx, ny});
            visited[nx][ny]=true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        cin>>W>>H;
        if(W==0 && H==0) break;
        
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin>>map[i][j];
            }
        }
        
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j]==1 && !visited[i][j]){
                    visited[i][j]=true;
                    q.push({i, j});
                    bfs();
                    ans++;
                }
            }
        }
        
        cout<<ans<<"\n";
        ans=0;
        q={};
        memset(visited, false, sizeof(visited));
    }
}