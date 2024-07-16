#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, K;
bool visited[1000001];
queue<pair<int, int>> q;

bool bfs(){
    while(!q.empty()){
        int cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(cur==N && cnt<=K){
            return true;
        }
        
        if(cnt==K) continue;
        
        int next1=cur+1;
        if(next1<=N && !visited[next1]){
            visited[next1]=true;
            q.push({next1, cnt+1});
        }
        
        int next2=cur+cur/2;
        if(next2<=N && !visited[next2]){
            visited[next2]=true;
            q.push({next2, cnt+1});
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>K;
    q.push({0, 0});
    visited[0]=true;
    
    cout<<(bfs() ? "minigimbob" : "water");
}