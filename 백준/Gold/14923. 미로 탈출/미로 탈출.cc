#include <bits/stdc++.h>
using namespace std;

int N, M, Hx, Hy, Ex, Ey, arr[1001][1001];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[1001][1001][2];
queue<tuple<int, int, int, int>> q;

int solve(){
    q.push({Hx, Hy, 0, 0});
    visited[Hx][Hy][0]=true;
    
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int cnt=get<2>(q.front());
        int cane=get<3>(q.front());
        q.pop();
        
        if(x==Ex && y==Ey) return cnt;
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1 || ny<1 || nx>N || ny>M) continue;
            if(visited[nx][ny][cane]) continue;
            if(arr[nx][ny]==1){
                if(cane==1) continue;
                q.push({nx, ny, cnt+1, 1});
                visited[nx][ny][1]=true;
            } else{
                q.push({nx, ny, cnt+1, cane});
                visited[nx][ny][cane]=true;
            }
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>Hx>>Hy>>Ex>>Ey;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
        }
    }
    
    cout<<solve();
}