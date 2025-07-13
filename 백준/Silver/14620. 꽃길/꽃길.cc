#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, arr[11][11], sel[3], ans=INF;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[65];

void solve(int cnt, int prev){
    if(cnt==3){
        int temp=0;
        for(int i=0; i<3; i++){
            int x=sel[i]/(N-2)+1;
            int y=sel[i]%(N-2)+1;
            temp+=arr[x][y];
            
            for(int j=0; j<4; j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                temp+=arr[nx][ny];
            }
        }
        ans=min(ans, temp);
        return;
    }
    
    for(int i=prev; i<(N-2)*(N-2); i++){
        if(!visited[i]){
            int x=i/(N-2)+1;
            int y=i%(N-2)+1;
            bool flag=false;
            for(int j=0; j<cnt; j++){
                int tx=sel[j]/(N-2)+1;
                int ty=sel[j]%(N-2)+1;
                if(abs(x-tx)+abs(y-ty)<=2){
                    flag=true;
                    break;
                }
            }
            if(flag) continue;
            
            visited[i]=true;
            sel[cnt]=i;
            solve(cnt+1, i);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    
    solve(0, 0);
    cout<<ans;
}