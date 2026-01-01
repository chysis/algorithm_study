#include <bits/stdc++.h>
using namespace std;

int N, M, arr[21][21], tempSum=0, ans=-1;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<int, int>> q;
bool visited[21][21];

int bfs(int i, int j){
    q.push({i, j});
    visited[i][j]=true;
    int cnt=1; // 시작점부터 카운트
    bool flag=false; // 실패 여부(에워싸이지 않은 경우에 실패)
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny]) continue;
            
            if(arr[nx][ny]==0){
                flag=true;
                continue;
            }
            else if(arr[nx][ny]==1) continue;
            
            q.push({nx, ny});
            visited[nx][ny]=true;
            cnt++;
        }
    }
    
    if(flag) return -1;
    return cnt;
}

void solve(int one, int two){
    arr[one/M][one%M]=1;
    arr[two/M][two%M]=1;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]!=2 || visited[i][j]) continue;
            
            int res=bfs(i, j);
            if(res==-1) q={};
            else tempSum+=res;
        }
    }
    
    ans=max(ans, tempSum);
    tempSum=0;
    memset(visited, false, sizeof(visited));
    
    arr[one/M][one%M]=0;
    arr[two/M][two%M]=0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<N*M; i++){
        if(arr[i/M][i%M]!=0) continue;
        for(int j=i+1; j<N*M; j++){
            if(arr[j/M][j%M]!=0) continue;
            solve(i, j);
        }
    }
    
    cout<<ans;
}