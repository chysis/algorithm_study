#include <string>
#include <iostream>
#include <vector>
#include <queue>

#define INF (~0U>>2)
using namespace std;

int dist[20001];
vector<int> adj[20001];
priority_queue<pair<int, int>> pq;

int solution(int n, vector<vector<int>> edge) {
    // dist 초기화
    for(int i=1; i<=n; i++) dist[i]=INF;
    
    // 주어진 edge 연결
    for(int i=0; i<edge.size(); i++){
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    // 다익스트라(우선순위 큐 이용)
    dist[1]=0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        
        for(int i=0; i<adj[cur].size(); i++){
            int next=adj[cur][i];
            
            if(dist[next]>cost+1){
                pq.push({cost+1, next});
                dist[next]=cost+1;
            }
        }
    }
    
    int ans=0, maxVal=-1;
    for(int i=1; i<=n; i++){
        if(dist[i]>maxVal){
            ans=1;
            maxVal=dist[i];
        }else if(dist[i]==maxVal){
            ans++;
        }
    }
    
    return ans;
}