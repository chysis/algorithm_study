#include <iostream>
using namespace std;

int map[20][20];
bool visited[9][20][20];

int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

// 오목인지?
bool search(int x, int y, int dir){
    int cnt=1;
    while(true){
        int nx=x+dx[dir]*cnt;
        int ny=y+dy[dir]*cnt;
        if(map[nx][ny]==map[x][y] && !visited[dir][nx][ny]) {
            visited[dir][nx][ny]=true;
            cnt++;
        }
        else break;
    }
    
    if(cnt==5) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=1; i<=19; i++){
        for(int j=1; j<=19; j++){
            cin>>map[i][j];
        }
    }
    
    for(int j=1; j<=19; j++){
        for(int i=1; i<=19; i++){
            if(map[i][j]==0) continue;
            
            for(int dir=0; dir<8; dir++){
                int nx=i+dx[dir];
                int ny=j+dy[dir];
                if(map[nx][ny]==map[i][j]){
                    if(!visited[dir][i][j]){
                        visited[dir][i][j]=true;
                        if(search(i, j, dir)){
                            cout<<map[i][j]<<"\n"<<i<<" "<<j;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    
    cout<<0;
}