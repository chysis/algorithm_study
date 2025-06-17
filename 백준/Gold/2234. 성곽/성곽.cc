#include <bits/stdc++.h>
using namespace std;

int N, M, zonearr[51][51], zonecnt[51*51], zone=1;
int dx[4]={0, -1, 0, 1}; // 서북동남
int dy[4]={-1, 0, 1, 0};
bool arr[51][51][4], visited[51][51];
queue<pair<int, int>> q;

void solve(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
            if(visited[nx][ny]) continue;
            if(arr[x][y][i]) continue;
            
            q.push({nx, ny});
            visited[nx][ny]=true;
            zonearr[nx][ny]=zone;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            int num;
            cin>>num;
            for(int k=3; k>=0; k--){
                if(num==0) break;
                if(num>=pow(2, k)) {
                    arr[i][j][k]=true;
                    num-=pow(2, k);
                }
            }
        }
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                visited[i][j];
                zonearr[i][j]=zone;
                q.push({i, j});
                solve();
                zone++;
            }
        }
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            zonecnt[zonearr[i][j]]++;
        }
    }
    
    int zoneMax=-1;
    for(int i=1; i<zone; i++){
        zoneMax=max(zoneMax, zonecnt[i]);
    }
    
    int twozoneMax=1;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<4; k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
                if(zonearr[i][j]!=zonearr[nx][ny]){
                    twozoneMax=max(twozoneMax, zonecnt[zonearr[i][j]]+zonecnt[zonearr[nx][ny]]);
                }
            }
        }
    }
    
    cout<<zone-1<<"\n"<<zoneMax<<"\n"<<twozoneMax;
}