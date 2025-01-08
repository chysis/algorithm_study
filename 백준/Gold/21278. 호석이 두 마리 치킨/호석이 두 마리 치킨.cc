#include <iostream>
#include <algorithm>

#define INF (~0U>>2)
using namespace std;

int adj[101][101];

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
        adj[A][B]=adj[B][A]=1;
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(adj[i][j]>adj[i][k]+adj[k][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
    
    int ans1, ans2, ans3=INF;
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            int temp=0;
            for(int k=1; k<=N; k++){
                if(i==k || j==k) continue;
                temp+=(min(adj[k][i], adj[k][j]))*2;
            }
            if(ans3>temp){
                ans1=i, ans2=j, ans3=temp;
            }
        }
    }
    
    cout<<ans1<<" "<<ans2<<" "<<ans3;
}