#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, indeg[1001], ans[1001];
vector<int> adj[1001];
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>A>>B;
        adj[A].push_back(B);
        indeg[B]++;
    }
    
    for(int i=1; i<=N; i++){
        ans[i]=1;
        if(indeg[i]==0) q.push({i, 1});
    }
    
    while(!q.empty()){
        int cur=q.front().first;
        int cnt=q.front().second;
        ans[cur]=cnt;
        q.pop();
        
        for(auto a: adj[cur]){
            indeg[a]--;
            if(indeg[a]==0){
                q.push({a, cnt+1});
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        cout<<ans[i]<<" ";
    }
}