#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF (~0U>>2)
using namespace std;

int V, dist[100001];
vector<pair<int, int>> adj[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start){
    pq.push({0, start});
    dist[start]=0;
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(curDist>dist[curNode]) continue;
        
        for(int i=0; i<adj[curNode].size(); i++){
            int nextNode=adj[curNode][i].first;
            int nextDist=curDist+adj[curNode][i].second;
            if(dist[nextNode]>nextDist){
                pq.push({nextDist, nextNode});
                dist[nextNode]=nextDist;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>V;
    for(int i=0; i<V; i++){
        int s, e, d;
        cin>>s;
        while(true){
            cin>>e;
            if(e==-1) break;
            cin>>d;
            adj[s].push_back({e, d});
        }
    }

    int targetNode, targetDist=-1;
    for(int i=1; i<=V; i++){
        dist[i]=INF;
    }
    dijkstra(1);
    for(int i=1; i<=V; i++){
        if(targetDist<dist[i]){
            targetNode=i;
            targetDist=dist[i];
        }
    }
    
    int ans=0;
    for(int i=1; i<=V; i++){
        dist[i]=INF;
    }
    dijkstra(targetNode);
    for(int j=1; j<=V; j++){
        ans=max(ans, dist[j]);
    }
    cout<<ans;
}