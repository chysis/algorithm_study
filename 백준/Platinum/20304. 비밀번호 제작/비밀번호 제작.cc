#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[100001];
int visit[1000001];
queue<pair<int, int>> q;

int bfs(){
    int res=0;
    
    while(!q.empty()){
        int now=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        res=max(res, cnt);
        
        for(int i=0; i<20; i++){
            int next=now^(1<<i);
            if(next>N || visit[next]!=-1) continue;
            q.push({next, cnt+1});
            visit[next]=cnt+1;
        }
    }
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>arr[i];
    }

    for(int i=0; i<=N; i++){
        visit[i]=-1;
    }
    
    for(int i=0; i<M; i++){
        q.push({arr[i], 0});
        visit[arr[i]]=0;
    }
    
    cout<<bfs();
}