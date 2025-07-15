#include <bits/stdc++.h>
using namespace std;

int T, H, W;
char arr[101][101];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<int, int>> q;
bool visited[101][101];

void solve(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=H || ny>=W) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny]=='.') continue;
            
            q.push({nx, ny});
            visited[nx][ny]=true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>H>>W;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin>>arr[i][j];
            }
        }
        
        int ans=0;
        
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(!visited[i][j] && arr[i][j]=='#'){
                    visited[i][j]=true;
                    q.push({i, j});
                    solve();
                    ans++;
                }
            }
        }
        
        cout<<ans<<"\n";
        q={};
        memset(visited, false, sizeof(visited));
    }
}