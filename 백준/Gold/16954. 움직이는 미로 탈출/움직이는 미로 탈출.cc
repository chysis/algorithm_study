#include <bits/stdc++.h>
using namespace std;

bool ans=false;
char arr[9][9][9];
int dx[9]={0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9]={0, 0, 1, 1, 1, 0, -1, -1, -1};
queue<pair<pair<int, int>, int>> q;
bool visited[9][9][9];

void solve(){
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cur=q.front().second;
        q.pop();
        
        if(arr[min(cur, 7)][x][y]=='#') continue;
        if(x==0 && y==7){
            ans=true;
            return;
        }
        
        for(int i=0; i<9; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=8 || ny>=8) continue;
            if(arr[cur][nx][ny]=='#') continue;
            if(visited[nx][ny][cur+1]) continue;
            
            visited[nx][ny][cur+1]=true;
            q.push({{nx, ny}, cur+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>arr[0][i][j];
        }
    }
    
    for(int i=1; i<8; i++){
        for(int j=0; j<8; j++){
            for(int k=0; k<8; k++){
                arr[i][j][k]='.';
            }
        }
        
        for(int j=6; j>=0; j--){
            for(int k=0; k<8; k++){
                arr[i][j+1][k]=arr[i-1][j][k];
            }
        }
    }
    
    q.push({{7, 0}, 0});
    solve();
    
    if(ans) cout<<"1";
    else cout<<"0";
}