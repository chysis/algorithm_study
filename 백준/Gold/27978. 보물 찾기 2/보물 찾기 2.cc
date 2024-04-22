#include <iostream>
#include <queue>

#define INF 987654321
using namespace std;

int dx[8]={-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8]={1, 1, 1, 0, -1, -1, -1, 0};

int H, W;
pair<int, int> target;
char map[501][501];
int visited[501][501];
queue<pair<pair<int, int>, int>> q;

void solve(){
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        
        for(int i=0; i<3; i++){
            int nx=cur.first.first+dx[i];
            int ny=cur.first.second+dy[i];
            
            if(nx<0 || ny<0 || nx>=H || ny>=W) continue;
            if(map[nx][ny]=='#') continue;
            if(visited[nx][ny]<=cur.second) continue;
            
            visited[nx][ny]=cur.second;
            q.push({{nx, ny}, cur.second});
        }
        
        for(int i=3; i<8; i++){
            int nx=cur.first.first+dx[i];
            int ny=cur.first.second+dy[i];
            
            if(nx<0 || ny<0 || nx>=H || ny>=W) continue;
            if(map[nx][ny]=='#') continue;
            if(visited[nx][ny]<=cur.second+1) continue;
            
            visited[nx][ny]=cur.second+1;
            q.push({{nx, ny}, cur.second+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>H>>W;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            visited[i][j]=INF;
        }
    }
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>map[i][j];
            if(map[i][j]=='K'){
                q.push({{i, j}, 0});
            } else if(map[i][j]=='*'){
                target={i, j};   
            }
        }
    }
    
    solve();
    
    if(visited[target.first][target.second]==INF){
        cout<<-1;
    } else{
        cout<<visited[target.first][target.second];
    }
}