#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
using namespace std;

int N, M, S, E;
int cnt=0;
int dist[1001];
int prevPath[1001];
vector<int> path;
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(){
    dist[S]=0;
    pq.push({0, S});
    
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        if(dist[curNode]<curDist) continue;
        
        for(int i=0; i<adj[curNode].size(); i++){
            int nextDist=curDist+adj[curNode][i].second;
            int nextNode=adj[curNode][i].first;
            
            if(dist[nextNode]>nextDist){
                dist[nextNode]=nextDist;
                prevPath[nextNode]=curNode;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    
    for(int i=1; i<=N; i++){
        dist[i]=INF;
    }
    
    for(int i=0; i<M; i++){
        int A, B, C;
        cin>>A>>B>>C;
        adj[A].push_back({B, C});
    }
    
    cin>>S>>E;
    
    dijkstra();
    
    int idx=E;
    path.push_back(E);
    while(true){
        if(prevPath[idx]==S) break;
        cnt++;
        path.push_back(prevPath[idx]);
        idx=prevPath[idx];
    }
    path.push_back(S);
    cout<<dist[E]<<"\n"<<path.size()<<"\n";
    
    reverse(path.begin(), path.end());
    for(auto a: path){
        cout<<a<<" ";
    }
}