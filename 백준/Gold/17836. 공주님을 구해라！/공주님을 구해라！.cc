#include <bits/stdc++.h>
using namespace std;

int N, M, T, gx, gy, arr[101][101], dist[101][101], ans;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[101][101], canGet=false;
queue<pair<int, int>> q;

void solve(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        if(dist[x][y]>T) continue;
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny]==1) continue;
            if(arr[nx][ny]==2) canGet=true;

            visited[nx][ny]=true;
            q.push({nx, ny});
            dist[nx][ny]=dist[x][y]+1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>T;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2) gx=i, gy=j;
        }
    }
    
    q.push({0, 0});
    visited[0][0]=true;
    dist[0][0]=0;
    solve();
    
    int temp1=dist[N-1][M-1];
    int temp2=dist[gx][gy]+abs(N-1-gx)+abs(M-1-gy);

    if(!canGet) {
        if(temp1==0 || temp1>T) cout<<"Fail";
        else cout<<temp1;
    } else{
        if(temp1>T && temp2>T) cout<<"Fail";
        else if(temp1==0){
            if(temp2<=T) cout<<temp2;
            else cout<<"Fail";
        } else cout<<min(temp1, temp2);
    }
}