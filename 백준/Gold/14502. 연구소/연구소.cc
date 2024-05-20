#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int ans=0;
int map[9][9];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<int, int>> q;
bool visited[9][9];

void solve(int a, int b, int c){
    int tempMap[9][9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            tempMap[i][j]=map[i][j];
        }
    }
    
    tempMap[a/M][a%M]=1;
    tempMap[b/M][b%M]=1;
    tempMap[c/M][c%M]=1;
    
    q={};
    memset(visited, false, sizeof(visited));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tempMap[i][j]==2){
                q.push({i, j});
                visited[i][j]=true;
            }
        }
    }
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        tempMap[x][y]=2;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && tempMap[nx][ny]==0 && !visited[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny]=true;
            }
        }
    }
    
    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tempMap[i][j]==0) cnt++;
        }
    }
    
    ans=max(ans, cnt);
}

int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<N*M; i++){
        for(int j=i+1; j<N*M; j++){
            for(int k=j+1; k<N*M; k++){
                if(map[i/M][i%M]!=0 || map[j/M][j%M]!=0 || map[k/M][k%M]!=0) continue;
                solve(i, j, k);
            }
        }
    }
    cout<<ans;
}