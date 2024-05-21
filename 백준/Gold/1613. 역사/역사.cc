#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int adj[401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         if(i==j) adj[i][j]=0;
    //         else adj[i][j]=INF;
    //     }
    // }
    
    for(int i=0; i<K; i++){
        int A, B;
        cin>>A>>B;
        adj[A][B]=-1;
        adj[B][A]=1;
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(adj[i][j]==0){
                    if(adj[i][k]==1 && adj[k][j]==1) adj[i][j]=1;
                    else if(adj[i][k]==-1 && adj[k][j]==-1) adj[i][j]=-1;
                }
            }
        }
    }
    
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    int T;
    cin>>T;
    while(T--){
        int A, B;
        cin>>A>>B;
        cout<<adj[A][B]<<"\n";
    }
}