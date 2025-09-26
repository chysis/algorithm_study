#include <bits/stdc++.h>
using namespace std;

int R, C, arr[6][6];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<tuple<int, int, int>> q;
bool visited[6][6];

int solve(){
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int cnt=get<2>(q.front());
        q.pop();
        
        if(arr[x][y]==1) return cnt;
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=5 || ny>=5) continue;
            if(arr[nx][ny]==-1) continue;
            if(visited[nx][ny]) continue;
            
            q.push({nx, ny, cnt+1});
            visited[nx][ny]=true;
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }
    cin>>R>>C;
    
    q.push({R, C, 0});
    cout<<solve();
}