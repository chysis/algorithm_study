#include <iostream>
#include <queue>

#define INF 987654321
using namespace std;

int N;
int arr[1001];
bool visited[1001];
queue<pair<int, int>> q;

int bfs(){
    while(!q.empty()){
        int cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(cur==N) return cnt;
        
        for(int i=1; i<=arr[cur]; i++){
            int next=cur+i;
            
            if(next>N) break;
            if(visited[next]) continue;
            
            q.push({next, cnt+1});
            visited[next]=true;
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    q.push({1, 0});
    visited[1]=true;
    cout<<bfs();
}