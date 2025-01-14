#include <iostream>
#include <vector>

#define INF (~0U>>2)
using namespace std;

int TC, N, M, W, dist[501];
vector<pair<pair<int, int>, int>> edge;

void addEdge(int s, int e, int t){
    bool updated=false;
    
    for(auto& ed: edge){
        if(ed.first.first==s && ed.first.second==e){
            if(t<ed.second){
                ed.second=t;
            }
            updated=true;
            break;
        }
    }
    
    if(!updated){
        edge.push_back({{s, e}, t});
    }
}

bool solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<edge.size(); j++){
            int s=edge[j].first.first;
            int e=edge[j].first.second;
            int t=edge[j].second;
            
            if(dist[s]+t<dist[e]){
                if(i==N-1) return true;
                dist[e]=dist[s]+t;
            }
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>TC;
    while(TC--){
        cin>>N>>M>>W;
        
        for(int i=1; i<=N; i++){
            dist[i]=INF;
        }
        
        for(int i=0; i<M; i++){
            int S, E, T;
            cin>>S>>E>>T;
            addEdge(S, E, T);
            addEdge(E, S, T);
        }
        
        for(int i=0; i<W; i++){
            int S, E, T;
            cin>>S>>E>>T;
            addEdge(S, E, -T);
        }
        
        bool ans=solve();
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
        
        edge.clear();
    }
}