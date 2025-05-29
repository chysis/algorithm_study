#include <bits/stdc++.h>
using namespace std;

int M, N, ans=0;
int dx[4]={-1, 1, 0, 0}; // 상하좌우
int dy[4]={0, 0, -1, 1};
char arr[1001][1001];
bool wall[1001][1001][4], visited[1001][1001][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>M>>N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]=='X'){
                for(int d=0; d<4; d++){
                    int nx=i+dx[d];
                    int ny=j+dy[d];
                    if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
                    if(arr[nx][ny]=='.') wall[i][j][d]=true;
                }
            }
        }
    }
    
    // 가로 방향
    for(int i=0; i<M; i++){
        for(int j=1; j<N-2; j++){
            if(arr[i][j]=='X'){
                if(!wall[i][j][0] && !wall[i][j][1]) continue;
                
                for(int k=0; k<=1; k++){
                    if(visited[i][j][k]) continue;
                    if(wall[i][j][k] && !visited[i][j][k]){
                        if(wall[i][j+1][k]){
                            visited[i][j][k]=visited[i][j+1][k]=true;
                            ans++;
                        }
                    }
                }
            }
        }
    }
    
    // 세로로 방향
    for(int i=1; i<M-2; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]=='X'){
                if(!wall[i][j][2] && !wall[i][j][3]) continue;
                
                for(int k=2; k<=3; k++){
                    if(visited[i][j][k]) continue;
                    if(wall[i][j][k] && !visited[i][j][k]){
                        if(wall[i+1][j][k]){
                            visited[i][j][k]=visited[i+1][j][k]=true;
                            ans++;
                        }
                    }
                }
            }
        }
    }
    
    cout<<ans;
}