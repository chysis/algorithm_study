#include <bits/stdc++.h>
using namespace std;

int N, arr[1001][1001], dp[1001][1001][3];

int solve(int x, int y, int now){
    if(x==N || y==N) return 0;
    int& temp=dp[x][y][now];
    if(temp!=-1) return temp;

    if(arr[x][y]==now){
        temp=max({
            solve(x+1, y, now), 
            solve(x, y+1, now), 
            solve(x+1, y, (now+1)%3)+1, 
            solve(x, y+1, (now+1)%3)+1
        });
    } else temp=max(solve(x+1, y, now), solve(x, y+1, now));
    
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-1;
        }
    }
    
    cout<<solve(0, 0, 0);
}