#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF (~0U>>2)
using namespace std;

int T, N, M, A, B, C, K;
int friends[101], adj[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=0; i<=N; i++){
            for(int j=0; j<=N; j++){
                if(i==j) adj[i][j]=0;
                else adj[i][j]=INF;
            }
        }
        
        for(int i=0; i<M; i++){
            cin>>A>>B>>C;
            adj[A][B]=adj[B][A]=C;
        }
        
        cin>>K;
        for(int i=0; i<K; i++){
            cin>>friends[i];
        }
        
        for(int k=1; k<=N; k++){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(i==j) continue;
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        
        int ans, ansVal=INF;
        for(int i=1; i<=N; i++){
            int temp=0;
            for(int j=0; j<K; j++){
                temp+=adj[friends[j]][i];
            }
            
            if(temp<ansVal){
                ansVal=temp;
                ans=i;
            }
        }
        
        cout<<ans<<"\n";
    }
}