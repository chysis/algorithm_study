#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N;
queue<int> q;
pair<int, char> ans[20001];
bool visited[20001];

void bfs(){
    memset(visited, false, sizeof(visited));
    q={};
    
    visited[1]=true;
    q.push(1);
    ans[1]={-1, '1'}; // 이전 나머지값, 추가한 숫자
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        int temp[2];
        temp[0]=(cur*10)%N;
        temp[1]=(cur*10+1)%N;
        
        for(int i=0; i<2; i++){
            if(visited[temp[i]]) continue;
            
            visited[temp[i]]=true;
            ans[temp[i]]={cur, i+'0'};
            
            if(temp[i]==0) return;
            q.push(temp[i]);
        }
    }
}

void track(int prev){
    if(prev==-1) return;
    
    track(ans[prev].first);
    cout<<ans[prev].second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        bfs();
        track(0);
        cout<<"\n";
    }
}