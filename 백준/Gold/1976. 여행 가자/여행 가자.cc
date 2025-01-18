#include <iostream>
#include <algorithm>
using namespace std;

int N, M, plan[1001], adj[201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>adj[i][j];
        }
    }
    
    for(int i=0; i<M; i++){
        cin>>plan[i];
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                adj[i][j]=adj[i][j] | (adj[i][k]&adj[k][j]);
            }
        }
    }
    
    bool flag=false;
    for(int i=0; i<M-1; i++){
        if(plan[i]==plan[i+1]) continue;
        if(adj[plan[i]][plan[i+1]]==0){
            flag=true;
            break;
        }
    }
    
    if(flag) cout<<"NO";
    else cout<<"YES";
}