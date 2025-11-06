#include <bits/stdc++.h>
using namespace std;

// F에서부터 거꾸로 탐색하면서 닿을 수 있는 곳 개수 찾기
int N, ans=0;
char arr[2001][2001];
int dx[7]={-1, -1, 0, 1, 1, 0, -1};
int dy[7]={0, 1, 1, 1, -1, -1, -1};
queue<pair<int, int>> q;
bool visited[2001][2001];

void solve(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<7; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if(visited[nx][ny] || arr[nx][ny]=='#') continue;
            
            visited[nx][ny]=true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='F') q.push({i, j});
        }
    }
    
    solve();
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] && arr[i][j]=='.') ans++;
        }
    }
    cout<<ans;
}