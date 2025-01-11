#include <iostream>
#include <queue>
#include <vector>

#define INF (~0U>>2)
using namespace std;

int N, M, adj[1001][1001], dist[1001];
vector<int> path[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve(){
    dist[1]=0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(curDist>dist[curNode]) continue;
        
        for(int i=1; i<=N; i++){
            if(curNode==i || adj[curNode][i]==0) continue;
            
            int nextDist=curDist+adj[curNode][i];
            if(nextDist<dist[i]){
                dist[i]=nextDist;
                pq.push({nextDist, i});
                path[i].clear();
                path[i].push_back(curNode);
            } else if(nextDist==dist[i]){
                path[i].push_back(curNode);
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
    
    for(int i=0; i<M; i++){
        int A, B, C;
        cin>>A>>B>>C;
        adj[A][B]=adj[B][A]=C;
    }
    
    solve();
    
    cout<<N-1<<"\n";
    for(int i=2; i<=N; i++){
        cout<<i<<" "<<path[i].back()<<"\n";
    }
    
}