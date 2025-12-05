#include <bits/stdc++.h>
using namespace std;

int N, num, ans, maxV=-1;
bool adj[1001][1001], visited[1001];

void solve(int start){
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({start, 1});
    visited[start]=true;
    
    int curAns, curMax=-1;
    
    while(!q.empty()){
        int cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(curMax<cnt){
            curMax=cnt;
            curAns=cur;
        }
        
        for(int i=1; i<=N; i++){
            if(i!=start && adj[cur][i] && !visited[i]){
                q.push({i, cnt+1});
                visited[i]=true;
            }
        }
    }
    
    if(curMax>maxV){
        maxV=curMax;
        ans=start;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>num;
        adj[i][num]=true;
    }
    
    for(int i=1; i<=N; i++){
        solve(i);
    }
    
    cout<<ans;
}