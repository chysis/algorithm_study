#include <bits/stdc++.h>
using namespace std;

int T, N, D, num, sel[21], ans=-1;
vector<int> adj[21];
bool selected[21];

bool check(int size){
    bool visited[21];
    memset(visited, false, sizeof(visited));
    
    for(int i=0; i<size; i++){
        visited[sel[i]]=true;
        for(auto next: adj[sel[i]]){
            visited[next]=true;
        }
    }
    
    for(int i=1; i<=N; i++){
        if(!visited[i]) return false;
    }
    return true;
}

void solve(int size, int cnt, int prev){
    if(size==cnt){
        if(check(size)) ans=size;
        return;
    }
    
    if(ans!=-1) return;
    
    for(int i=prev+1; i<=N; i++){
        if(!selected[i]){
            selected[i]=true;
            sel[cnt]=i;
            solve(size, cnt+1, i);
            selected[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1; i<=N; i++){
            cin>>D;
            for(int j=0; j<D; j++){
                cin>>num;
                adj[i].push_back(num);
                adj[num].push_back(i);
            }
        }
        
        for(int i=1; i<=N; i++){
            solve(i, 0, -1);
            if(ans!=-1){
                cout<<ans<<"\n";
                break;
            }
        }
        
        for(int i=1; i<=N; i++) adj[i].clear();
        memset(selected, false, sizeof(selected));
        ans=-1;
    }
}