#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, arr[1001][1001], dp[2][1001][1001], ans=-INF;
int dx[2]={-1, 0};
int dy[2]={0, 1};

void solve(int sx, int sy, int opt){
    queue<tuple<int, int, int>> q;
    q.push({arr[sx][sy], sx, sy});
    
    while(!q.empty()){
        int cost=get<0>(q.front());
        int x=get<1>(q.front());
        int y=get<2>(q.front());
        q.pop();
        
        if(cost<dp[opt][x][y]) continue;

        for(int i=0; i<2; i++){
            int nx=x+dx[i];
            int ny=y+dy[i]*(opt==1 ? -1 : 1);
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            
            int nCost=cost+arr[nx][ny];

            if(nCost>dp[opt][nx][ny]){
                dp[opt][nx][ny]=nCost;
                q.push({nCost, nx, ny});
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
            dp[0][i][j]=dp[1][i][j]=-INF;
        }
    }
    
    dp[0][N-1][0]=arr[N-1][0], solve(N-1, 0, 0);
    dp[1][N-1][M-1]=arr[N-1][M-1], solve(N-1, M-1, 1);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            ans=max(ans, dp[0][i][j]+dp[1][i][j]);
        }
    }
    
    cout<<ans;
}