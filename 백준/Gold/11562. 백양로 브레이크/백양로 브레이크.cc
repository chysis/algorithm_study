#include <iostream>

#define INF 987654321
using namespace std;

int adj[251][251];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) adj[i][j]=0;
            else adj[i][j]=INF;
        }
    }
    
    for(int i=0; i<M; i++){
        int U, V, B;
        cin>>U>>V>>B;
        adj[U][V]=0;
        adj[V][U]=(B==0?1:0);
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    int K;
    cin>>K;
    for(int i=0; i<K; i++){
        int S, E;
        cin>>S>>E;
        cout<<adj[S][E]<<"\n";
    }
}