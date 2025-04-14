#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, A, B, K, G, U, V, L, route[1001], dist[1001];
vector<pair<int, int>> adj[1001];
vector<tuple<int, int, int, int>> notice;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int validateRoad(int s, int e, int t){ // 기다려야 하는 시간 반환
    for(auto it: notice){
        if((get<0>(it)==s && get<1>(it)==e) || (get<0>(it)==e && get<1>(it)==s)){
            if(get<2>(it)<=t && t<get<3>(it)){
                return get<3>(it)-t;
            }
        }
    }
    return 0;
}

void solve(){
    dist[A]=K;
    pq.push({K, A});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(curDist>dist[curNode]) continue;
        
        for(int i=0; i<adj[curNode].size(); i++){
            int nextNode=adj[curNode][i].first;
            int cost=adj[curNode][i].second;
            int nextDist=curDist+cost+validateRoad(curNode, nextNode, curDist);

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
    
    cin>>N>>M;
    cin>>A>>B>>K>>G;
    for(int i=0; i<=N; i++){
        dist[i]=INF;
    }
    
    for(int i=0; i<G; i++){
        cin>>route[i];
    }
    
    for(int i=0; i<M; i++){
        cin>>U>>V>>L;
        adj[U].push_back({V, L});
        adj[V].push_back({U, L});
    }
    
    // 도로 통제 상황 
    int t=0;
    for(int i=0; i<G-1; i++){
        int s=route[i], e=route[i+1], dist;
        for(int j=0; j<adj[s].size(); j++){
            if(adj[s][j].first==e){
                dist=adj[s][j].second;
                break;
            }
        }
        notice.push_back({s, e, t, t+dist});
        t+=dist;
    }
    
    solve();
    cout<<dist[B]-K;
}