#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

#define INF 987654321
using namespace std;

int dist[10001];
vector<pair<int, int>> arr[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve(){
    while(!pq.empty()){
        int curDist=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        
        if(dist[curNode]<curDist) continue;
        
        for(auto a: arr[curNode]){
            int nextDist=curDist+a.second;
            int nextNode=a.first;
            
            if(dist[nextNode]>nextDist){
                dist[nextNode]=nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N, D, C;
        cin>>N>>D>>C;
        
        for(int i=1; i<=N; i++){
            dist[i]=INF;
        }
        
        for(int i=0; i<D; i++){
            int a, b, s;
            cin>>a>>b>>s;
            
            arr[b].push_back({a, s});
        }
        
        dist[C]=0;
        pq.push({0, C});
        solve();
        
        int cnt=0;
        int ans=-1;
        for(int i=1; i<=N; i++){
            if(dist[i]!=INF){
                cnt++;
                ans=max(ans, dist[i]);
            }
        }
        
        cout<<cnt<<" "<<ans<<"\n";
        
        for(int i=1; i<=N; i++){
            arr[i].clear();
        }
        pq={};
    }
}