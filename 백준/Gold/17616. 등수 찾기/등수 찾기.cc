#include <bits/stdc++.h>
using namespace std;

int N, M, X, A, B, pre=0;
vector<int> adj[100001];
queue<int> q;
bool visited[100001];

int bfs(){
    int cnt=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        for(auto next: adj[cur]){
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
        if(B==X) pre++;
    }
    
    q.push(X);
    int res=bfs();
    
    cout<<1+pre<<" "<<N-res;
}