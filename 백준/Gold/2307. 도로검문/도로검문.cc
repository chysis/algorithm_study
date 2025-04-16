#include <bits/stdc++.h>
#define INF (~0U>>2)
#define pii pair<int, int>
using namespace std;

int N, M, A, B, T, dist[1001], prevNode[1001];
vector<int> path;
vector<pii> adj[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void solve(){
    dist[1]=0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int curNode=pq.top().second;
        int curDist=pq.top().first;
        pq.pop();
        
        if(dist[curNode]<curDist) continue;
        
        for(int i=0; i<adj[curNode].size(); i++){
            int nextNode=adj[curNode][i].first;
            int nextDist=curDist+adj[curNode][i].second;
            
            if(dist[nextNode]>nextDist){
                dist[nextNode]=nextDist;
                prevNode[nextNode]=curNode;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

void newSolve(int banS, int banE){
    dist[1]=0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int curNode=pq.top().second;
        int curDist=pq.top().first;
        pq.pop();
        
        if(dist[curNode]<curDist) continue;
        
        for(int i=0; i<adj[curNode].size(); i++){
            int nextNode=adj[curNode][i].first;
            int nextDist=curDist+adj[curNode][i].second;
            
            if((curNode==banS && nextNode==banE) || (curNode==banE && nextNode==banS)) continue;
            if(dist[nextNode]>nextDist){
                dist[nextNode]=nextDist;
                prevNode[nextNode]=curNode;
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
        dist[i]=INF;
    }
    
    for(int i=0; i<M; i++){
        cin>>A>>B>>T;
        adj[A].push_back({B, T});
        adj[B].push_back({A, T});
    }
    
    solve();
    int origAns=dist[N];
    
    int idx=N;
    path.push_back(N);
    while(true){
        if(prevNode[idx]==1) break;
        path.push_back(prevNode[idx]);
        idx=prevNode[idx];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    
    int ans=0;
    for(int i=0; i<path.size()-1; i++){
        pq.empty();
        for(int j=1; j<=N; j++){
            dist[j]=INF;
        }
        
        int banS=path[i], banE=path[i+1];
        
        newSolve(banS, banE);
        if(dist[N]==INF){
            ans=-1;
            break;
        } else{
            ans=max(ans, max(0, dist[N]-origAns));
        }
    }
    
    cout<<ans;
}