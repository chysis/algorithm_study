#include <bits/stdc++.h>
using namespace std;

int N, M, ans=0;
char arr[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    // 가로
    for(int i=0; i<N; i++){
        for(int j=0; j<M-2; j++){
            if(arr[i][j]=='F' && arr[i][j+1]=='O' && arr[i][j+2]=='X') ans++;
            else if(arr[i][j]=='X' && arr[i][j+1]=='O' && arr[i][j+2]=='F') ans++;
        }
    }
    
    // 세로
    for(int i=0; i<N-2; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]=='F' && arr[i+1][j]=='O' && arr[i+2][j]=='X') ans++;
            else if(arr[i][j]=='X' && arr[i+1][j]=='O' && arr[i+2][j]=='F') ans++;
        }
    }
    
    // 좌상우하 대각선
    for(int i=0; i<N-2; i++){
        for(int j=0; j<M-2; j++){
            if(arr[i][j]=='F' && arr[i+1][j+1]=='O' && arr[i+2][j+2]=='X') ans++;
            else if(arr[i][j]=='X' && arr[i+1][j+1]=='O' && arr[i+2][j+2]=='F') ans++;
        }
    }
    
    // 우상좌하 대각선
    for(int i=N-1; i>=2; i--){
        for(int j=0; j<M-2; j++){
            if(arr[i][j]=='F' && arr[i-1][j+1]=='O' && arr[i-2][j+2]=='X') ans++;
            else if(arr[i][j]=='X' && arr[i-1][j+1]=='O' && arr[i-2][j+2]=='F') ans++;
        }
    }
    cout<<ans;
}