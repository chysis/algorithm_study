#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#define INF (~0U>>2)
using namespace std;

int V, dist[100001];
bool visited[100001];
vector<pair<int, int>> adj[100001];

void dfs(int start, int prevDist){
    for(int i=0; i<adj[start].size(); i++){
        int nextNode=adj[start][i].first;
        if(visited[nextNode]) continue;
        
        int nextDist=prevDist+adj[start][i].second;
        dist[nextNode]=nextDist;
        visited[nextNode]=true;
        dfs(nextNode, nextDist);
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

    for(int i=1; i<=V; i++){
        dist[i]=INF;
    }
    dist[1]=0;
    dfs(1, 0);

    int maxNode, maxDist=-1;
    for(int i=1; i<=V; i++){
        if(maxDist<dist[i]){
            maxDist=dist[i];
            maxNode=i;
        }
    }
    memset(visited, false, sizeof(visited));

    for(int i=1; i<=V; i++){
        dist[i]=INF;
    }
    dist[maxNode]=0;
    dfs(maxNode, 0);
    
    int ans=0;
    for(int i=1; i<=V; i++){
        if(i==maxNode) continue;
        ans=max(ans, dist[i]);
    }
    cout<<ans;
}