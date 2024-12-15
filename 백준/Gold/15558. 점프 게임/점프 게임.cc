#include <iostream>
#include <queue>
using namespace std;

int map[2][100001];
queue<pair<int, pair<int, int>>> q;
bool visited[2][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin>>N>>K;
    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            char c;
            cin>>c;
            map[i][j]=c-'0';
        }
    }
    
    q.push({0, {0, 0}});
    visited[0][0]=true;
    bool isClear=false;
    
    while(!q.empty()){
        int cnt=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        q.pop();
        
        if(y==N-1 || y+K>=N){
            isClear=true;
            break;
        }
        
        if(map[(x+1)%2][y+K]==1 && !visited[(x+1)%2][y+K] && cnt+1<=y+K){
            q.push({cnt+1, {(x+1)%2, y+K}});
            visited[(x+1)%2][y+K]=true;
        }
        
        if(y+1<N && map[x][y+1]==1 && !visited[x][y+1] && cnt+1<=y+1){
            q.push({cnt+1, {x, y+1}});
            visited[x][y+1]=true;
        }
        
        if(y-1>=0 && map[x][y-1]==1 && !visited[x][y-1] && cnt+1<=y-1){
            q.push({cnt+1, {x, y-1}});
            visited[x][y-1]=true;
        }
    }
    
    if(isClear) cout<<1;
    else cout<<0;
}