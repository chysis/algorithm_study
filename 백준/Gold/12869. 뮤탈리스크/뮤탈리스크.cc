#include <bits/stdc++.h>
using namespace std;

int INF=INT_MAX;
int N, arr[3];
int dp[61][61][61];
int o[6][3]={
    {0, 1, 2}, {0, 2, 1}, {1, 0, 2},
    {1, 2, 0}, {2, 0, 1}, {2, 1, 0}
};
int dmg[3] = {9, 3, 1};
queue<pair<array<int, 3>, int>> q;

int bfs(){
    while(!q.empty()){
        array<int, 3> cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(cur[0]==0 && cur[1]==0 && cur[2]==0) return cnt;
        
        for(int i=0; i<6; i++){
            array<int, 3> next=cur;
            for(int j=0; j<3; j++){
                next[o[i][j]]=max(0, next[o[i][j]] - dmg[j]);
            }
            if(dp[next[0]][next[1]][next[2]] > cnt+1){
                dp[next[0]][next[1]][next[2]] = cnt+1;
                q.push({next, cnt+1});
            }
        }
    }
    return -1; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<3; i++){
        if(i<N) cin >> arr[i];
        else arr[i] = 0;
    }
    
    for(int i=0; i<61; i++){
        for(int j=0; j<61; j++){
            for(int k=0; k<61; k++){
                dp[i][j][k]=INF;
            }
        }
    }
    
    dp[arr[0]][arr[1]][arr[2]]=0;
    q.push({{arr[0], arr[1], arr[2]}, 0});
    cout<<bfs();
}
