#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF (~0U>>2)
using namespace std;

int N, E, V1, V2, adj[801][801], dist[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void init(){
    for(int i=1; i<=N; i++){
        dist[i]=INF;
    }
    pq={};
}

void solve(int start){
    dist[start]=0;
    pq.push({0, start});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(curDist>dist[curNode]) continue;
        
        for(int i=1; i<=N; i++){
            if(curNode==i || adj[curNode][i]==0) continue;
            if(curDist+adj[curNode][i]<dist[i]){
                dist[i]=curDist+adj[curNode][i];
                pq.push({curDist+adj[curNode][i], i});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>E;
    
    for(int i=1; i<=N; i++){
        dist[i]=INF;
    }
    
    for(int i=0; i<E; i++){
        int A, B, C;
        cin>>A>>B>>C;
        adj[A][B]=C;
        adj[B][A]=C;
    }
    
    cin>>V1>>V2;
    
    solve(1);
    int stov1=dist[V1], stov2=dist[V2];
    init();
    
    solve(V1);
    int v1tov2=dist[V2], v1toe=dist[N];
    init();
    
    solve(V2);
    int v2tov1=dist[V1], v2toe=dist[N];

    if(stov1+v1tov2+v2toe>=INF && stov2+v2tov1+v1toe>=INF){
        cout<<-1;
        return 0;
    }
    
    cout<<min(stov1+v1tov2+v2toe, stov2+v2tov1+v1toe);
}