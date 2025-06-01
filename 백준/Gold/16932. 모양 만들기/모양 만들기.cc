#include <bits/stdc++.h>
using namespace std;

int N, M, arr[1001][1001], zone[1001][1001], zoneSize[500001], cnt=1;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[1001][1001];

void solve(int x, int y){
    queue<pair<int, int>> q;
    zone[x][y]=cnt;
    q.push({x, y});
    int temp=1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(arr[nx][ny]==0) continue;
            if(visited[nx][ny]) continue;
            
            visited[nx][ny]=true;
            zone[nx][ny]=cnt;
            temp++;
            q.push({nx, ny});
        }
    }
    
    zoneSize[cnt]=temp;
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
            if(arr[i][j]==1 && !visited[i][j]){
                visited[i][j]=true;
                solve(i, j);
                cnt++;
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==0){
                set<int> s;
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                    
                    s.insert(zone[nx][ny]);
                }
                
                int temp=1;
                for(auto a: s) temp+=zoneSize[a];
                ans=max(ans, temp);
            }
        }
    }
    
    cout<<ans;
}