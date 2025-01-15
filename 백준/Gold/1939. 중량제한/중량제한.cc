#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF (~0U>>2)
using namespace std;

int N, M, V1, V2, dist[10001];
vector<pair<int, int>> adj[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

void addEdge(int s, int e, int c){
    bool updated=false;
    
    for(auto& ed: adj[s]){
        if(ed.first==e){
            if(ed.second<c){
                ed.second=c;
            }
            updated=true;
            break;
        }
    }
    
    if(!updated){
        adj[s].push_back({e, c});
    }
}

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