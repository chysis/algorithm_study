#include <iostream>
#include <queue>
using namespace std;

int total=0, cnt=0;
int N, M, sx, sy;
char map[1001][1001];
int mapCounter[1001][1001];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j]=='@'){
                sx=i, sy=j;
            }
            else if(map[i][j]=='*' || map[i][j]=='#') total++;
        }
    }
    
    for(int i=0; i<4; i++){
        bool flag=true;
        for(int j=1; j<=2; j++){
            if(!flag) continue;
            int nx=sx+dx[i]*j;
            int ny=sy+dy[i]*j;
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(map[nx][ny]=='*' && mapCounter[nx][ny]>0) continue;
            if(map[nx][ny]=='#' && mapCounter[nx][ny]>1) continue;
            if(map[nx][ny]=='|') flag=false;
            
            mapCounter[nx][ny]++;
            if(map[nx][ny]=='*' && mapCounter[nx][ny]==1) {
                q.push({nx, ny});
                cnt++;
            }
            if(map[nx][ny]=='#' && mapCounter[nx][ny]==2) {
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    
    while(!q.empty()){
        int curX=q.front().first;
        int curY=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(map[nx][ny]=='*' && mapCounter[nx][ny]>0) continue;
            if(map[nx][ny]=='#' && mapCounter[nx][ny]>1) continue;
            
            mapCounter[nx][ny]++;
            if(map[nx][ny]=='*' && mapCounter[nx][ny]==1) {
                q.push({nx, ny});
                cnt++;
            }
            if(map[nx][ny]=='#' && mapCounter[nx][ny]==2) {
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    
    cout<<cnt<<" "<<total-cnt;
}