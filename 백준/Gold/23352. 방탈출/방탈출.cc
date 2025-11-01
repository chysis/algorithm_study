#include <bits/stdc++.h>
using namespace std;

int N, M, arr[51][51], len=1, sum=0;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[51][51];

void solve(int x, int y){
    queue<tuple<int, int, int>> q;
    q.push({x, y, 1});
    visited[x][y]=true;
    
    int curSum=arr[x][y]*2;
    if(len==1 && curSum>sum) sum=curSum;
    
    while(!q.empty()){
        int cx=get<0>(q.front());
        int cy=get<1>(q.front());
        int cnt=get<2>(q.front());
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny]==0) continue;
            
            q.push({nx, ny, cnt+1});
            visited[nx][ny]=true;
            
            int curSum=arr[x][y]+arr[nx][ny];
            if(cnt>len){
                len=cnt;
                sum=curSum;
            }else if(cnt==len){
                if(curSum>sum) sum=curSum;
            }
        }
    }
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
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]!=0){
                solve(i, j);
                memset(visited, false, sizeof(visited));
            }
        }
    }
    
    cout<<sum;
}