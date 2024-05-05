#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, bit;
int sX, sY;
char map[51][51];
bool visited[51][51][64];

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

queue<tuple<int, int, int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j]=='0'){
                sX=i, sY=j;
            }
        }
    }
    
    q.push({sX, sY, 0, 0});
    visited[sX][sY][0]=true;
    
    while(!q.empty()){
        int curX=get<0>(q.front());
        int curY=get<1>(q.front());
        int cnt=get<2>(q.front());
        int curBit=get<3>(q.front());
        q.pop();
        
        if(map[curX][curY]=='1'){
            cout<<cnt;
            return 0;
        }
        
        for(int i=0; i<4; i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            int nB=curBit;
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            
            if('a'<=map[nx][ny] && map[nx][ny]<='f'){
                nB|=(1<<(map[nx][ny]-'a'));

                if(!visited[nx][ny][nB]){
                    visited[nx][ny][nB]=true;
                    q.push({nx, ny, cnt+1, nB});
                }
            }
            else if('A'<=map[nx][ny] && map[nx][ny]<='F'){
                if((nB & (1<<(map[nx][ny]-'A')))==(1<<(map[nx][ny]-'A'))){
                    if(!visited[nx][ny][nB]){
                        visited[nx][ny][nB]=true;
                        q.push({nx, ny, cnt+1, nB});
                    }
                }
            }
            else if(map[nx][ny]!='#' && !visited[nx][ny][nB]){
                visited[nx][ny][nB]=true;
                q.push({nx, ny, cnt+1, nB});
            }
        }
    }
    
    cout<<-1;
}