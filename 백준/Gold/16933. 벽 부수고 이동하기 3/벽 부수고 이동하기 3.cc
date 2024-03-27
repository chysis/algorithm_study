#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, K;
char map[1001][1001];
int cnt[1001][1001][11][2];
bool visited[1001][1001][11][2];

queue<tuple<int, int, int, int>> q;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int solve(){
    while(!q.empty()){
        int curX=get<0>(q.front());
        int curY=get<1>(q.front());
        int breakCnt=get<2>(q.front());
        int dayNight=get<3>(q.front());
        q.pop();
        
        if(curX==N-1 && curY==M-1){
            return cnt[curX][curY][breakCnt][dayNight];
        }
        
        for(int i=0; i<4; i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny][breakCnt][1-dayNight]) continue;
            
            if(map[nx][ny]=='1'){
                if(dayNight==1) continue;
                if(breakCnt==K) continue;
                
                q.push({nx, ny, breakCnt+1, 1-dayNight});
                visited[nx][ny][breakCnt+1][1-dayNight]=true;
                cnt[nx][ny][breakCnt+1][1-dayNight]=cnt[curX][curY][breakCnt][dayNight]+1;
            } else{
                q.push({nx, ny, breakCnt, 1-dayNight});
                visited[nx][ny][breakCnt][1-dayNight]=true;
                cnt[nx][ny][breakCnt][1-dayNight]=cnt[curX][curY][breakCnt][dayNight]+1;
            }
        }
        
        if(dayNight==1 && !visited[curX][curY][breakCnt][1-dayNight]){
            visited[curX][curY][breakCnt][1-dayNight]=true;
            q.push({curX, curY, breakCnt, 1-dayNight});
            cnt[curX][curY][breakCnt][1-dayNight]=cnt[curX][curY][breakCnt][dayNight]+1;
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    q.push({0, 0, 0, 0});
    cnt[0][0][0][0]=1;
    visited[0][0][0][0]=true;
    
    cout<<solve();
}