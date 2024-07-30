#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N;
bool cycle=false;
vector<int> adj[3001];
bool isCycle[3001];
bool visited[3001];
int ans[3001];

queue<pair<int, int>> q;

void findCycle(int cur, int start, int cnt){
    if(cur==start && cnt>=2){
        cycle=true;
        return;
    }
    
    visited[cur]=true;

    for(auto next: adj[cur]){
        if(!visited[next]) findCycle(next, start, cnt+1);
        else {
            if(next==start && cnt>=2){
                cycle=true;
                return;
            }
        }
        
        if(cycle) return;
    }
}

int bfs(){
    memset(visited, false, sizeof(visited));
    
    while(!q.empty()){
        int cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(isCycle[cur]) return cnt;
        
        for(auto a: adj[cur]){
            if(visited[a]) continue;
            
            visited[a]=true;
            q.push({a, cnt+1});
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=0; i<N; i++){
        int A, B;
        cin>>A>>B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    for(int i=1; i<=N; i++){
        memset(visited, false, sizeof(visited));
        cycle=false;
        
        findCycle(i, i, 0);
        if(cycle) isCycle[i]=true;
    }
    
    for(int i=1; i<=N; i++){
        if(isCycle[i]) ans[i]=0;
        else{
            q.push({i, 0});
            visited[i]=true;
            ans[i]=bfs();
            
            q={};
        }
    }
    
    for(int i=1; i<=N; i++){
        cout<<ans[i]<<" ";
    }
}