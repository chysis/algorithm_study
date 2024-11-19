#include <iostream>
#include <queue>

#define INF 987654321
using namespace std;

int N, M, PR, PC, curDir;
char map[501][501];
char dir[4]={'U', 'R', 'D', 'L'};
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

queue<pair<pair<int, int>, int>> q;

int bfs(){
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        
        if(cnt==N*M*2+1) return INF;
        if(map[x][y]=='C') return cnt-1;
        
        int nx=x+dx[curDir];
        int ny=y+dy[curDir];
        if(nx<1 || ny<1 || nx>N || ny>M) return cnt;
        if(map[nx][ny]=='/'){
            if(curDir%2==0) curDir++;
            else curDir--;
        } else if(map[nx][ny]=='\\'){
            if(curDir==0) curDir=3;
            else if(curDir==1) curDir=2;
            else if(curDir==2) curDir=1;
            else curDir=0;
        }
        q.push({{nx, ny}, cnt+1});
    }
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>map[i][j];
        }
    }
    
    cin>>PR>>PC;
    
    int ans=-1;
    char dirAns;
    for(int i=0; i<4; i++){
        curDir=i; 
        q.push({{PR, PC}, 1});
        
        int t=bfs();
        if(t==INF){
            dirAns=dir[i];
            ans=INF;
            break;
        }
        
        if(ans<t){
            dirAns=dir[i];
            ans=t;
        }
        
        q={};
    }
    
    cout<<dirAns<<"\n";
    if(ans==INF) cout<<"Voyager";
    else cout<<ans;
}