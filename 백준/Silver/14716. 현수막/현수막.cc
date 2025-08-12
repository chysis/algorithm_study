#include <bits/stdc++.h>
using namespace std;

int M, N, arr[251][251];
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
bool visited[251][251];
queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny]==0) continue;
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
    
    int ans=0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && arr[i][j]==1){
                visited[i][j]=true;
                q.push({i, j});
                bfs();
                ans++;
            }
        }
    }
    cout<<ans;
}