#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int ans=-1, leaf=-1;
vector<pair<int, int>> v[10001];
bool visited[10001];

void dfs(int start, int dist){
    if(ans<dist){
        ans=dist;
        leaf=start;
    }
    
    visited[start]=true;
    
    for(int i=0; i<v[start].size(); i++){
        if(!visited[v[start][i].first]){
            dfs(v[start][i].first, dist+v[start][i].second);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N-1; i++){
        int A, B, C;
        cin>>A>>B>>C;
        v[A].push_back({B, C});
        v[B].push_back({A, C});
    }
    
    dfs(1, 0);
    ans=-1;
    memset(visited, false, sizeof(visited));
    dfs(leaf, 0);
    cout<<ans;
}