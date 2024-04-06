#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

int res=0;
char arr[6][6];
bool visited[25];
int ans[7];
bool map[6][6];
bool mapVisited[6][6];

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

queue<pair<int, int>> q;

bool isNeighbor(){
    int cnt=1;
    memset(map, false, sizeof(map));
    memset(mapVisited, false, sizeof(mapVisited));
    
    for(int i=0; i<7; i++){
        map[ans[i]/5][ans[i]%5]=true;
    }
    
    q.push({ans[0]/5, ans[0]%5});
    mapVisited[ans[0]/5][ans[0]%5]=true;
    
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            
            if(mapVisited[nx][ny]) continue;
            if(!map[nx][ny]) continue;
            
            mapVisited[nx][ny]=true;
            q.push({nx, ny});
            cnt++;
        }
    }
    
    if(cnt!=7) return false;
    return true;
}

bool isPromising(){
    int s=0, y=0;
    for(int i=0; i<7; i++){
        if(arr[ans[i]/5][ans[i]%5]=='S') s++;
        else y++;
    }
    
    if(s>=4) return true;
    else return false;
}

void solve(int cnt, int idx){
    if(cnt==7){
        if(isPromising()){
            if(isNeighbor()) res++;
        }
        return;
    }
    
    for(int i=idx; i<25; i++){
        if(!visited[i]){
            visited[i]=true;
            ans[cnt]=i;
            solve(cnt+1, i);
            visited[i]=false;
        }
    }
}

int main()
{
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }
    
    solve(0, 0);
    cout<<res;
}