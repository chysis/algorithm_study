#include <bits/stdc++.h>
using namespace std;

int T, N, M, X, Y, color[1001];
vector<int> adj[1001];
queue<int> q;
bool ans=true, visited[1001];

void solve(){
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        for(auto next: adj[cur]){
            if(visited[next]){
                if(cur!=next && color[next]==color[cur]){
                    ans=false; // 사이클을 통해 같은 색끼리 인접
                    return;
                } else continue;
            }
            
            color[next]=color[cur]==1 ? 2 : 1;
            q.push(next);
            visited[next]=true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=0; i<M; i++){
            cin>>X>>Y;
            adj[X].push_back(Y);
            adj[Y].push_back(X);
        }
        
        for(int i=1; i<=N; i++){
            if(!ans) break;
            if(!visited[i]){
                visited[i]=true;
                color[i]=1;
                q.push(i);
                solve();
            }
        }
        
        if(ans) cout<<"possible\n";
        else cout<<"impossible\n";
        
        for(int i=1; i<=N; i++){
            adj[i].clear();
            color[i]=0;
            visited[i]=false;
        }
        q={};
        ans=true;
    }
}