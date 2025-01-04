#include <iostream>
#include <queue>

#define INF (~0U>>2)
using namespace std;

int N, M, S, E;
int adj[1001][1001], dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve(int start){
    dist[start]=0;
    pq.push({0, start});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(curDist>dist[curNode]) continue;
        for(int i=1; i<=N; i++){
            if(i==curNode || adj[curNode][i]==INF) continue;
            
            int nextDist=curDist+adj[curNode][i];
            if(nextDist<dist[i]){
                dist[i]=nextDist;
                pq.push({nextDist, i});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=1; i<=N; i++){
        dist[i]=INF;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            adj[i][j]=INF;
        }
    }
    
    for(int i=0; i<M; i++){
        int A, B, C;
        cin>>A>>B>>C;
        adj[A][B]=min(adj[A][B], C);
    }
    
    cin>>S>>E;
    solve(S);
    
    cout<<dist[E];
}