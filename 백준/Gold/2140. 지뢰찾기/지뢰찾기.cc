#include <iostream>
using namespace std;

int N;
char map[101][101];
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    
    if(N==1 || N==2){
        cout<<0;
        return 0;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    
    map[1][1]=(map[0][0]=='0' ? '-' : '*');
    map[1][N-2]=(map[0][N-1]=='0' ? '-' : '*');
    map[N-2][1]=(map[N-1][0]=='0' ? '-' : '*');
    map[N-2][N-2]=(map[N-1][N-1]=='0' ? '-' : '*');
    
    for(int i=1; i<N-3; i++){
        int num=map[0][i]-'0';
        
        int cnt=0;
        if(map[1][i-1]=='*') cnt++;
        if(map[1][i]=='*') cnt++;
        
        if(num>cnt) map[1][i+1]='*';
        else map[1][i+1]='-';
    }
    
    for(int i=1; i<N-3; i++){
        int num=map[N-1][i]-'0';
        
        int cnt=0;
        if(map[N-2][i-1]=='*') cnt++;
        if(map[N-2][i]=='*') cnt++;
        
        if(num>cnt) map[N-2][i+1]='*';
        else map[N-2][i+1]='-';
    }
    
    for(int i=1; i<N-3; i++){
        int num=map[i][0]-'0';
        
        int cnt=0;
        if(map[i-1][1]=='*') cnt++;
        if(map[i][1]=='*') cnt++;
        
        if(num>cnt) map[i+1][1]='*';
        else map[i+1][1]='-';
    }
    
    for(int i=1; i<N-3; i++){
        int num=map[i][N-1]-'0';
        
        int cnt=0;
        if(map[i-1][N-2]=='*') cnt++;
        if(map[i][N-2]=='*') cnt++;
        
        if(num>cnt) map[i+1][N-2]='*';
        else map[i+1][N-2]='-';
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]=='#' || map[i][j]=='*') ans++;
        }
    }
    
    cout<<ans;
}