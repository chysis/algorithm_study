#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int arr[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            arr[i][j]=INF;
        }
    }
    
    for(int i=0; i<M; i++){
        int A, B;
        cin>>A>>B;
        arr[B][A]=1;
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                arr[i][j]=min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]==INF) arr[i][j]=0;
        }
    }
    
    int ans=0;
    for(int i=1; i<=N; i++){
        int cnt=0;
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            if(arr[i][j]>0 || arr[j][i]>0) cnt++;
        }
        
        if(cnt==N-1) ans++;
    }
    
    cout<<ans;
}