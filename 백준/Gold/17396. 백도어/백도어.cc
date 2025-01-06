#include <iostream>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

int N, M;
ll INF = (ll)100001*(ll)100001+1;
ll dist[100001];
bool sight[100001];
vector<pair<int, int>> adj[100001];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void print(){
    
}

void solve(){
    dist[0]=0;
    pq.push({0, 0});
    
    while(!pq.empty()){
        ll curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(curDist>dist[curNode]) continue;
        
        for(int i=0; i<adj[curNode].size(); i++){
            int nextNode=adj[curNode][i].first;
            ll nextDist=curDist+adj[curNode][i].second;

            if(nextDist<dist[nextNode] && (!sight[nextNode] || nextNode==N-1)){
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
    for(int i=0; i<N; i++){
        cin>>sight[i];
    }
    
    for(int i=0; i<N; i++){
        dist[i]=INF;
    }
    
    for(int i=0; i<M; i++){
        int A, B, T;
        cin>>A>>B>>T;
        adj[A].push_back({B, T});
        adj[B].push_back({A, T});
    }
    
    solve();
    
    cout<<(dist[N-1]==INF ? -1 : dist[N-1]);
}