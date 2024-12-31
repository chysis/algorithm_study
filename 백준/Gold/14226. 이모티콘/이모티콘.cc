#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int S;
queue<tuple<int, int, int>> q; // 현재 개수, 클립보드에 있는 개수, cnt
bool visited[2001][2001];

int bfs(){
    while(!q.empty()){
        int cur=get<0>(q.front());
        int clipboard=get<1>(q.front());
        int cnt=get<2>(q.front());
        q.pop();
        
        // cout<<"cur: "<<cur<<" clipboard: "<<clipboard<<" cnt: "<<cnt<<"\n";
        
        if(cur==S) return cnt;

        // 클립보드에 복사
        q.push({cur, cur, cnt+1});
        
        // 클립보드에서 붙여넣기
        if(!visited[cur+clipboard][clipboard] && cur+clipboard<=S){
            q.push({cur+clipboard, clipboard, cnt+1});
            visited[cur+clipboard][clipboard]=true;
        }
        
        // 하나 삭제
        if(cur-1>0 && !visited[cur-1][clipboard]){
            q.push({cur-1, clipboard, cnt+1});
            visited[cur-1][clipboard]=true;
        }
    }
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    q.push({1, 0, 0});
    visited[1][0]=true;
    cout<<bfs();
}