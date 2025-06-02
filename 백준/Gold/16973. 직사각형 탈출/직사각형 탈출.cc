#include <bits/stdc++.h>
#define t5i tuple<int, int, int, int, int>
using namespace std;

int N, M, H, W, Sr, Sc, Fr, Fc, arr[1001][1001];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[1001][1001]; // 왼쪽 위 기준
queue<t5i> q;

int solve(){
    while(!q.empty()){
        auto [sx, sy, fx, fy, cnt] {q.front()};
        q.pop();
        
        if(sx==Fr && sy==Fc) return cnt;
        
        for(int i=0; i<4; i++){
            int nsx=sx+dx[i], nsy=sy+dy[i];
            int nfx=fx+dx[i], nfy=fy+dy[i];
            
            if(nsx<1 || nsy<1 || nfx>N || nfy>M) continue;
            if(visited[nsx][nsy]) continue;
            
            bool canMove=true;
            if(i==0){
                for(int j=nsy; j<=nfy; j++){
                    if(arr[nsx][j]==1){
                        canMove=false;
                        break;
                    }
                }
            } else if(i==1){
                for(int j=nsy; j<=nfy; j++){
                    if(arr[nfx][j]==1){
                        canMove=false;
                        break;
                    }
                }
            } else if(i==2){
                for(int j=nsx; j<=nfx; j++){
                    if(arr[j][nsy]==1){
                        canMove=false;
                        break;
                    }
                }
            } else{
                for(int j=nsx; j<=nfx; j++){
                    if(arr[j][nfy]==1){
                        canMove=false;
                        break;
                    }
                }
            }
            
            if(!canMove) continue;
            visited[nsx][nsy]=true;
            q.push({nsx, nsy, nfx, nfy, cnt+1});
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
        }
    }
    cin>>H>>W>>Sr>>Sc>>Fr>>Fc;
    
    q.push({Sr, Sc, Sr+H-1, Sc+W-1, 0});
    visited[Sr][Sc]=true;
    cout<<solve();
}