#include <bits/stdc++.h>
using namespace std;

int N, M, X, A, B;
vector<int> adj[100001], adj2[100001];
queue<int> q;
bool visited[100001];

int bfs(bool isBack){
    int cnt=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        for(auto next: (isBack ? adj2[cur] : adj[cur])){
            if(visited[next]) continue;
            visited[next]=true;
            q.push(next);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>X;
    for(int i=0; i<M; i++){
        cin>>A>>B;
        adj[A].push_back(B);
        adj2[B].push_back(A);
    }
    
    q.push(X);
    int after=bfs(false);
    q={};
    
    q.push(X);
    int before=bfs(true);
    cout<<1+before<<" "<<N-after;
}