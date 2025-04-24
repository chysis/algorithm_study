#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int V, E, P, A, B, C, dist[5001];
vector<pair<int, int>> adj[5001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void init(){
    pq={};
    for(int i=1; i<=V; i++){
        dist[i]=INF;
    }
}

void solve(int start){
    dist[start]=0;
    pq.push({0, start});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(curDist>dist[curNode]) continue;
        
        for(auto next: adj[curNode]){
            int nextNode=next.first;
            int nextDist=curDist+next.second;
            
            if(nextDist<dist[nextNode]){
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
    
    cin>>V>>E>>P;
    init();
    
    for(int i=0; i<E; i++){
        cin>>A>>B>>C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }
    
    int minVal, partA, partB;
    solve(1);
    minVal=dist[V];
    partA=dist[P];
    
    init();
    solve(P);
    partB=dist[V];
    
    if(minVal==partA+partB) cout<<"SAVE HIM";
    else cout<<"GOOD BYE";
}