#include <bits/stdc++.h>
using namespace std;

int N, M, R, arr[301][301];

void solve(){
    for(int i=0; i<min(N/2, M/2); i++){
        int basis=arr[i][i];
        for(int j=i; j<M-1-i; j++){
            arr[i][j]=arr[i][j+1];
        }
        for(int j=i; j<N-1-i; j++){
            arr[j][M-1-i]=arr[j+1][M-1-i];
        }
        for(int j=M-1-i; j>i; j--){
            arr[N-1-i][j]=arr[N-1-i][j-1];
        }
        for(int j=N-1-i; j>i; j--){
            arr[j][i]=arr[j-1][i];
        }
        arr[i+1][i]=basis;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<R; i++) solve();
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}