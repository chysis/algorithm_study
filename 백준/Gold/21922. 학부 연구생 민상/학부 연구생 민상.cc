#include <bits/stdc++.h>
using namespace std;

int N, M, arr[2001][2001];
bool visited[2001][2001][4], cold[2001][2001];
vector<pair<int, int>> v; // 에어컨 위치

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

// type: 물건 번호, dir: 진행 방향
// -1이면 정지
int nextDir(int type, int dir){
    if(type==0 || type==9) return dir; // 그대로 직진
    else if(type==1){
        if(dir==2 || dir==3) return -1;
        else return dir;
    }
    else if(type==2){
        if(dir==0 || dir==1) return -1;
        else return dir;
    }
    else if(type==3){
        if(dir==0) return 3;
        else if(dir==1) return 2;
        else if(dir==2) return 1;
        else if(dir==3) return 0;
    }
    else if(type==4){
        if(dir==0) return 2;
        else if(dir==1) return 3;
        else if(dir==2) return 0;
        else if(dir==3) return 1;
    }
    
    return -1;
}

void bfs(int x, int y){
    queue<tuple<int, int, int>> q; // x, y, 방향
    cold[x][y]=true;
    for(int i=0; i<4; i++){
        if(!visited[x][y][i]){
            visited[x][y][i]=true;
            q.push({x, y, i});
        }
    }
    
    while(!q.empty()){
        auto [x, y, dir]=q.front();
        q.pop();
        
        int nDir=nextDir(arr[x][y], dir);
        if(nDir==-1) continue;
        
        int nx=x+dx[nDir];
        int ny=y+dy[nDir];
        if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
        if(visited[nx][ny][nDir]) continue;
        
        visited[nx][ny][nDir]=true;
        cold[nx][ny]=true;
        q.push({nx, ny, nDir});
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
            if(arr[i][j]==9) v.push_back({i, j});
        }
    }
    
    for(auto a: v){
        bfs(a.first, a.second);
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(cold[i][j]) ans++;
        }
    }
    
    cout<<ans;
}