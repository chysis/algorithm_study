#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, Q, p, q, r, k, v;
vector<pair<int, int>> arr[5001];
queue<pair<int, int>> qq;
bool visited[5001];

int bfs(int start, int k){
    int cnt=0;
    qq.push({start, INF});
    visited[start]=true;
    
    while(!qq.empty()){
        int cur=qq.front().first;
        int val=qq.front().second;
        qq.pop();
        
        for(auto next: arr[cur]){
            if(visited[next.first]) continue;
            if(min(val, next.second)<k) continue;
            visited[next.first]=true;
            qq.push({next.first, min(val, next.second)});
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>Q;
    for(int i=0; i<N-1; i++){
        cin>>p>>q>>r;
        arr[p].push_back({q, r});
        arr[q].push_back({p, r});
    }
    for(int i=0; i<Q; i++){
        cin>>k>>v;
        cout<<bfs(v, k)<<"\n";
        memset(visited, false, sizeof(visited));
    }
}