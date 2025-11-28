#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[101][101];

char solve(char c){
    if(c=='.') return '.';
    else if(c=='O') return 'O';
    else if(c=='-') return '|';
    else if(c=='|') return '-';
    else if(c=='/') return '\\';
    else if(c=='\\') return '/';
    else if(c=='^') return '<';
    else if(c=='<') return 'v';
    else if(c=='v') return '>';
    else if(c=='>') return '^';
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
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout<<solve(arr[j][M-1-i]);
        }
        cout<<"\n";
    }
}