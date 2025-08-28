#include <bits/stdc++.h>
using namespace std;

int N, M, ans=0;
char arr[201][201];

bool solve(char a, char b, char c, char d){
    if(a=='E' || a=='I'){
        if(b=='N' || b=='S'){
            if(c=='F' || c=='T'){
                if(d=='P' || d=='J'){
                    return true;
                }
            }
        }
    }
    
    if(a=='P' || a=='J'){
        if(b=='F' || b=='T'){
            if(c=='N' || c=='S'){
                if(d=='E' || d=='I'){
                    return true;
                }
            }
        }
    }
    return false;
}

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
        for(int j=0; j<M-3; j++){
            if(solve(arr[i][j],  arr[i][j+1], arr[i][j+2], arr[i][j+3])) ans++;
        }
    }
    
    // 세로
    for(int i=0; i<N-3; i++){
        for(int j=0; j<M; j++){
            if(solve(arr[i][j],  arr[i+1][j], arr[i+2][j], arr[i+3][j])) ans++;
        }
    }
    
    // \ 대각선
    for(int i=0; i<N-3; i++){
        for(int j=0; j<M-3; j++){
            if(solve(arr[i][j], arr[i+1][j+1], arr[i+2][j+2], arr[i+3][j+3])) ans++;
        }
    }
    
    // / 대각선
    for(int i=0; i<N-3; i++){
        for(int j=M-1; j>2; j--){
            if(solve(arr[i][j], arr[i+1][j-1], arr[i+2][j-2], arr[i+3][j-3])) ans++;
        }
    }
    cout<<ans;
}