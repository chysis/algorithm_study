#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int V, E, K;
int dist[20001];
vector<pair<int, int>> adj[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(){
    dist[K]=0;
    pq.push({0, K});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        for(int i=0; i<adj[curNode].size(); i++){
            int nextDist=curDist+adj[curNode][i].second;
            int nextNode=adj[curNode][i].first;
            
            if(dist[nextNode]>nextDist){
                dist[nextNode]=nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main()
{
    
    cin>>V>>E>>K;
    
    for(int i=1; i<=V; i++){
        dist[i]=INF;
    }
    
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        
        adj[u].push_back({v, w});
    }
    
    dijkstra();
    
    for(int i=1; i<=V; i++){
        if(dist[i]==INF) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
}