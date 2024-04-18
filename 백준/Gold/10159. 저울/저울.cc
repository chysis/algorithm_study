#include <iostream>
#include <memory.h>

#define INF 987654321   
using namespace std;

int adj[101][101];
bool canComp[101];

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
        int A, B;
        cin>>A>>B;
        adj[B][A]=1;
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(adj[i][j]==INF) adj[i][j]=0;
        }
    }
    
    for(int i=1; i<=N; i++){
        int cnt=1;
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            if(adj[i][j]>0 || adj[j][i]>0){
                cnt++;
            }
        }
        
        cout<<N-cnt<<"\n";
        memset(canComp, false, sizeof(canComp));
    }
}