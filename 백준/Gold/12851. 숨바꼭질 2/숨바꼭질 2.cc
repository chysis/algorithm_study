#include <iostream>
#include <algorithm>
#include <queue>

#define INF 987654321
using namespace std;

int N, K, ansCnt=0;
queue<pair<int, int>> q;
int visit[100001];

void bfs(){
    while(!q.empty()){
        int cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(cur==K) ansCnt++;
        
        int nx[3]={cur-1, cur+1, cur*2};
        for(int i=0; i<3; i++){
            if(nx[i]>100000) continue;
            if(visit[nx[i]]<cnt+1) continue;
            
            q.push({nx[i], cnt+1});
            visit[nx[i]]=cnt+1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>K;
    if(N==K){
        cout<<0<<"\n"<<1;
        return 0;
    }
    
    for(int i=0; i<=100000; i++){
        visit[i]=INF;
    }
    
    q.push({N, 0});
    bfs();
    cout<<visit[K]<<"\n"<<ansCnt;
}