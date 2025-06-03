#include <bits/stdc++.h>
using namespace std;

int N, K, S, X, Y, arr[201][201];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[201][201];
queue<pair<int, int>> q[1001];

bool isDone(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]==0) return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0) {
                q[arr[i][j]].push({i, j});
                visited[i][j]=true;
            }
        }
    }
    cin>>S>>X>>Y;
    
    int cnt=0;
    while(true){
        if(cnt==S) break;
        if(isDone()) break;
        
        for(int i=1; i<=K; i++){
            int rep=q[i].size();
            for(int j=0; j<rep; j++){
                int x=q[i].front().first;
                int y=q[i].front().second;
                q[i].pop();
                
                for(int k=0; k<4; k++){
                    int nx=x+dx[k], ny=y+dy[k];
                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    if(arr[nx][ny]!=0) continue;
                    if(visited[nx][ny]) continue;
                    
                    visited[nx][ny]=true;
                    q[i].push({nx, ny});
                    arr[nx][ny]=i; 
                }
            }
        }
        cnt++;
    }
    
    cout<<arr[X-1][Y-1];
}