#include <bits/stdc++.h>
using namespace std;

int M, N;
char arr[1001][1001];
queue<pair<int, int>> q;
bool visited[1001][1001];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

void solve(int x, int y){
    q={};
    q.push({x, y});
    visited[x][y]=true;
    
    while(!q.empty()){
        auto [x, y]=q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=M || ny>=N || arr[nx][ny]=='1') continue;
            if(visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny]=true;
        }
    }
}

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
    
    for(int i=0; i<N; i++){
        solve(0, i);
    }
    
    for(int i=0; i<N; i++){
        if(arr[M-1][i]=='0' && visited[M-1][i]) return cout<<"YES", 0;
    }
    cout<<"NO";
}