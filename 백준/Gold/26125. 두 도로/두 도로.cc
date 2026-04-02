#include <bits/stdc++.h>
#define INF (~0U>>2)
#define ll long long
using namespace std;

ll N, M, S, T, Q, u, v, w, a1, b1, c1, a2, b2, c2;
ll adj[301][301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>S>>T;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) adj[i][j]=0;
            else adj[i][j]=INF;
        }
    }
    
    for(int i=0; i<M; i++){
        cin>>u>>v>>w;
        adj[u][v]=min(adj[u][v], w);
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    cin>>Q;
    // 새로운 도로가 생길 때마다 다시 전체 최단 거리를 구하게 되면 O(N^3 * Q)가 되므로 시간 초과
    // 새로운 도로를 이용하는 최단 경로는 다음 4가지 시나리오로 정리 가능
    for(int i=0; i<Q; i++){
        cin>>a1>>b1>>c1>>a2>>b2>>c2;
        
        // 기존 경로만 이용
        ll s0=adj[S][T];
        
        // S -> 도로1 -> T
        ll s1=adj[S][a1]+c1+adj[b1][T];
        
        // S -> 도로2 -> T
        ll s2=adj[S][a2]+c2+adj[b2][T];
        
        // S -> 도로1 -> 도로2 -> T
        ll s3=adj[S][a1]+c1+adj[b1][a2]+c2+adj[b2][T];
        
        // S -> 도로2 -> 도로1 -> T
        ll s4=adj[S][a2]+c2+adj[b2][a1]+c1+adj[b1][T];
        
        if(min({s0, s1, s2, s3, s4}) >= INF) cout<<-1<<"\n";
        else cout<<min({s0, s1, s2, s3, s4})<<"\n";
    }
}