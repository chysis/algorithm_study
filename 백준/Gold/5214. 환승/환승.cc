#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, K, M, arr[1001][1001], dist[101111];
vector<int> adj[101111];
queue<pair<int, int>> q;

int bfs(){
    q.push({1, 1});
    dist[1]=1;
    
    while(!q.empty()){
        int cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(cur==N) return cnt;
        
        for(auto next: adj[cur]){
            if(next>N){
                q.push({next, cnt});
            } else{
                if(dist[next]>cnt+1){
                    q.push({next, cnt+1});
                    dist[next]=cnt+1;
                }
            }
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K>>M;
    
    for(int i=1; i<=N; i++) dist[i]=INF;
    
    for(int i=1; i<=M; i++){
        for(int j=0; j<K; j++){
            cin>>arr[i][j];
            adj[N+i].push_back(arr[i][j]);
            adj[arr[i][j]].push_back(N+i);
        }
    }
    
    if(N==1){
        cout<<1;
        return 0;
    }
    
    cout<<bfs();
}