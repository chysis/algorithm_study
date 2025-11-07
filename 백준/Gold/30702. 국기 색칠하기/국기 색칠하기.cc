#include <bits/stdc++.h>
using namespace std;

int N, M, flag1[51][51], flag2[51][51];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[51][51];

void solve(int x, int y, int from, int to){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y]=true;
    flag1[x][y]=flag2[x][y];
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visited[nx][ny] || flag1[nx][ny]!=from) continue;
            
            visited[nx][ny]=true;
            flag1[nx][ny]=to;
            q.push({nx, ny});
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
            char c; cin>>c;
            flag1[i][j]=c-'A';
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c; cin>>c;
            flag2[i][j]=c-'A';
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j]){
                solve(i, j, flag1[i][j], flag2[i][j]);
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(flag1[i][j]!=flag2[i][j]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}