#include <bits/stdc++.h>
using namespace std;

int K, V, E, u, v, color[20001];
vector<int> adj[20001];
queue<int> q;
bool flag=true, visited[20001];

void solve(){
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        for(auto next: adj[cur]){
            if(visited[next]){
                if(next!=cur && color[next]==color[cur]){
                    flag=false;
                    return;
                }
                continue;
            }
            
            color[next]=color[cur]==1 ? 2 : 1;
            visited[next]=true;
            q.push(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>K;
    while(K--){
        cin>>V>>E;
        for(int i=0; i<E; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=1; i<=V; i++){
            if(!flag) break;
            if(!visited[i]){
                visited[i]=true;
                color[i]=1;
                q.push(i);
                solve();
            }
        }
        
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
        
        for(int i=1; i<=V; i++){
            adj[i].clear();
            visited[i]=false;
            color[i]=0;
        }
        q={};
        flag=true;
    }
}