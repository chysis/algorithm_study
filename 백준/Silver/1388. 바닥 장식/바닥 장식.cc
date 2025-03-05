#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[51][51];
bool visited[51][51];

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
    
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j]) continue;
            
            if(arr[i][j]=='-'){
                visited[i][j]=true;
                int x=i, y=j;
                while(true){
                    int nx=x;
                    int ny=y+1;
                    if(ny>=M || arr[nx][ny]!='-') break;
                    visited[nx][ny]=true;
                    x=nx, y=ny;
                }
            } else if(arr[i][j]=='|'){
                visited[i][j]=true;
                int x=i, y=j;
                while(true){
                    int nx=x+1;
                    int ny=y;
                    if(nx>=N || arr[nx][ny]!='|') break;
                    visited[nx][ny]=true;
                    x=nx, y=ny;
                }
            }
            ans++;
        }
    }
    
    cout<<ans;
}