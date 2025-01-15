#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF (~0U>>2)
#define pii pair<int, int>
using namespace std;

int N, M, V1, V2, dist[10001];
vector<pii> adj[10001];
priority_queue<pii, vector<pii>, less<pii>> pq;

void solve(){
    dist[V1]=INF;
    pq.push({INF, V1});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(curDist<dist[curNode]) continue;
        
        for(int i=0; i<adj[curNode].size(); i++){
            int nextDist=min(curDist, adj[curNode][i].second);
            int nextNode=adj[curNode][i].first;

            if(nextDist>dist[nextNode]){
                dist[nextNode]=nextDist;
                pq.push({nextDist, nextNode});
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
        dist[i]=-1;    
    }
    
    for(int i=0; i<M; i++){
        int A, B, C;
        cin>>A>>B>>C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }
    
    cin>>V1>>V2;
    solve();
    
    cout<<dist[V2];
}