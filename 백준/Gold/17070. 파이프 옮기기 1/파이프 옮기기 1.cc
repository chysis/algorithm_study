#include <bits/stdc++.h>
using namespace std;

int N, arr[17][17], dp[17][17][3];

int solve(int x, int y, int opt){
    if(x>=N || y>=N || arr[x][y]==1) return 0;
    if(x==N-1 && y==N-1) return 1;
    int& temp=dp[x][y][opt];
    if(temp!=-1) return temp;
    temp=0;
    
    if(opt==0){
        temp+=solve(x, y+1, 0);
        if(arr[x+1][y]!=1 && arr[x][y+1]!=1 && arr[x+1][y+1]!=1) temp+=solve(x+1, y+1, 2);
    }else if(opt==1){
        temp+=solve(x+1, y, 1);
        if(arr[x+1][y]!=1 && arr[x][y+1]!=1 && arr[x+1][y+1]!=1) temp+=solve(x+1, y+1, 2);
    }else{
        temp+=solve(x, y+1, 0);
        temp+=solve(x+1, y, 1);
        if(arr[x+1][y]!=1 && arr[x][y+1]!=1 && arr[x+1][y+1]!=1) temp+=solve(x+1, y+1, 2);
    }
    
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
    
    cout<<solve(0, 1, 0);
}