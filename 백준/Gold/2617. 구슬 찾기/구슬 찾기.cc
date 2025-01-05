#include <iostream>

#define INF (~0U>>2)
using namespace std;

int adj[101][101], f[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            adj[i][j]=INF;
        }
    }
    for(int i=0; i<M; i++){
        int A, B;
        cin>>A>>B;
        adj[A][B]=1;
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i==j) continue;
                if(adj[i][j]>adj[i][k]+adj[k][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(adj[i][j]==INF) adj[i][j]=0;
        }
    }
    
    int ans=0;
    for(int i=1; i<=N; i++){
        int cnt=0;
        for(int j=1; j<=N; j++){
            if(adj[i][j]!=0) cnt++;
        }
        
        if(cnt>=((N+1)/2)) ans++;
    }
    
    for(int i=1; i<=N; i++){
        int cnt=0;
        for(int j=1; j<=N; j++){
            if(adj[j][i]!=0) cnt++;
        }
        
        if(cnt>=((N+1)/2)) ans++;
    }
    
    cout<<ans;
}