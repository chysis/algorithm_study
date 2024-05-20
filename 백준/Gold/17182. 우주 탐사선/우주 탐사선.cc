#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int N, K, ans=INF;
int map[11][11];
int track[11];
bool visited[11];

int getAnswer(){
    int temp=0;
    for(int i=0; i<N-1; i++){
        temp+=map[track[i]][track[i+1]];    
    }
    
    return temp;
}

void solve(int cnt){
    if(cnt==N){
        ans=min(ans, getAnswer());
        return;
    }
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i]=true;
            track[cnt]=i;
            solve(cnt+1);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            map[i][j]=INF;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j]=min(map[i][j], map[i][k]+map[k][j]);
            }
        }
    }
    
    visited[K]=true;
    track[0]=K;
    solve(1);
    cout<<ans;
}