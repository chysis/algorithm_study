#include <bits/stdc++.h>
using namespace std;

int T, N, K, X, Y, W, indeg[1001], cost[1001], ans[1001];
vector<int> adj[1001];
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N>>K;
        for(int i=1; i<=N; i++){
            cin>>cost[i];
        }
        
        for(int i=0; i<K; i++){
            cin>>X>>Y;
            adj[X].push_back(Y);
            indeg[Y]++;
        }
        
        cin>>W;
        
        for(int i=1; i<=N; i++){
            ans[i]=cost[i];
            if(indeg[i]==0) q.push({i, cost[i]});
        }
        
        while(!q.empty()){
            int cur=q.front().first;
            int curCost=q.front().second;
            q.pop();
            
            for(auto a: adj[cur]){
                indeg[a]--;
                ans[a]=max(ans[a], ans[cur]+cost[a]);
                if(indeg[a]==0){
                    q.push({a, curCost+cost[a]});
                }
            }
        }
        
        cout<<ans[W]<<"\n";
        
        q={};
        for(int i=1; i<=N; i++){
            adj[i].clear();
        }
    }
}