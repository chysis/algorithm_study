#include <iostream>
#include <queue>
using namespace std;

int N, M, P;
int turn=1;
int shoe[10];
int ans[10];
bool canPlay[10];
int map[1001][1001];

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

queue<pair<pair<int, int>, int>> q[10];

bool bfs(int cur){
    bool flag=false;
    queue<pair<pair<int, int>, int>> qq = q[cur];
    
    while(!qq.empty()){
        int x=qq.front().first.first;
        int y=qq.front().first.second;
        int cnt=qq.front().second;
        qq.pop();
        
        if(cnt==shoe[cur]) q[cur].pop();
        if(cnt==0) continue;
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(map[nx][ny]!=0) continue;
            
            ans[cur]++;
            q[cur].push({{nx, ny}, shoe[cur]});
            qq.push({{nx, ny}, cnt-1});
            map[nx][ny]=cur;
            flag=true;
        }
    }
    
    return flag;
}

bool keepGoing(){
    for(int i=1; i<=P; i++){
        if(canPlay[i]) return true;
    }
    return false;
}

int main()
{
    cin>>N>>M>>P;
    for(int i=1; i<=P; i++){
        cin>>shoe[i];
    }
    
    for(int i=1; i<=P; i++){
        canPlay[i]=true;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin>>c;
            if(c=='.') map[i][j]=0;
            else if(c=='#') map[i][j]=-1;
            else {
                map[i][j]=c-'0';
                q[map[i][j]].push({{i, j}, shoe[map[i][j]]});
                ans[map[i][j]]++;
            }
        }
    }
    
    while(true){
        for(int i=1; i<=P; i++){
            if(!canPlay[i]) continue;
            bool temp=bfs(i);
            if(!temp) canPlay[i]=false;
        }
        
        if(!keepGoing()) break;
    }

    for(int i=1; i<=P; i++){
        cout<<ans[i]<<" ";
    }
}