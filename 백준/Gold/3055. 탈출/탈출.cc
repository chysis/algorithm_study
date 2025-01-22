#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int R, C, tx, ty;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
char map[51][51];
deque<pair<int, pair<int, int>>> d;
deque<pair<int, int>> w;
bool done, dVisited[51][51], wVisited[51][51];

int moveDochi(){
    int rep=d.size();
    if(rep==0) return -1;
    
    for(int i=0; i<rep; i++){
        int cnt=d.front().first;
        int x=d.front().second.first;
        int y=d.front().second.second;
        d.pop_front();
        
        if(x==tx && y==ty){
            done=true;
            return cnt;
        }
        
        for(int j=0; j<4; j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
            if(dVisited[nx][ny]) continue;
            if(map[nx][ny]=='X' || map[nx][ny]=='*') continue;

            d.push_back({cnt+1, {nx, ny}});
            dVisited[nx][ny]=true;
            map[nx][ny]='S';
        }
    }
    
    return 0;
}

void moveWater(){
    int rep=w.size();
    if(rep==0) return;
    
    for(int i=0; i<rep; i++){
        int x=w.front().first;
        int y=w.front().second;
        w.pop_front();
        
        for(int j=0; j<4; j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
            if(wVisited[nx][ny]) continue;
            if(map[nx][ny]=='X' || map[nx][ny]=='D') continue;
            
            w.push_back({nx, ny});
            wVisited[nx][ny]=true;
            map[nx][ny]='*';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
            if(map[i][j]=='S'){
                d.push_back({0, {i, j}});
                dVisited[i][j]=true;
            } else if(map[i][j]=='D'){
                tx=i, ty=j;
            } else if(map[i][j]=='*'){
                w.push_back({i, j});
                wVisited[i][j]=true;
            }
        }
    }
    
    while(true){
        moveWater();
        int sig=moveDochi();
        if(sig==-1 && !done){
            cout<<"KAKTUS";
            break;
        }
        if(done){
            cout<<sig;
            break;
        }
    }
}