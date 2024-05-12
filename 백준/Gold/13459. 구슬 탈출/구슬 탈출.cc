#include <iostream>
#include <queue>
#include <tuple>

#define t4i tuple<int, int, int, int>
using namespace std;

int N, M, ans=0;
int rx, ry, bx, by, ox, oy;
char map[11][11];
queue<pair<t4i, int>> q;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

void bfs(){
    bool ok=false;
    while(!q.empty()){
        int curRx=get<0>(q.front().first);
        int curRy=get<1>(q.front().first);
        int curBx=get<2>(q.front().first);
        int curBy=get<3>(q.front().first);
        int cnt=q.front().second;
        q.pop();

        if(ok){
            ans=1;
            return;
        }
        
        if(cnt>10) break;
        
        for(int i=0; i<4; i++){
            bool redInHole=false;
            bool blueInHole=false;
            
            int nextRx=curRx;
            int nextRy=curRy;
            int nextBx=curBx;
            int nextBy=curBy;
            
            while(map[nextRx][nextRy]!='#'){
                nextRx+=dx[i];
                nextRy+=dy[i];
                if(nextRx==ox && nextRy==oy){
                    redInHole=true;
                    break;
                }
            }
            
            while(map[nextBx][nextBy]!='#'){
                nextBx+=dx[i];
                nextBy+=dy[i];
                if(nextBx==ox && nextBy==oy){
                    blueInHole=true;
                    break;
                }
            }
            
            if(redInHole && blueInHole) continue;
            else if(redInHole) {
                ans=1;
                ok=true;
            }
            
            nextRx-=dx[i];
            nextRy-=dy[i];
            nextBx-=dx[i];
            nextBy-=dy[i];
            
            if(nextRx==nextBx && nextRy==nextBy){
                if(curRx>curBx){ 
                    if(i==0){
                        nextRx-=dx[i];
                    }
                    else if(i==1){
                        nextBx-=dx[i];
                    }
                }
                else if(curRx<curBx){
                    if(i==0){
                        nextBx-=dx[i];
                    }
                    else if(i==1){
                        nextRx-=dx[i];
                    }
                }
                else if(curRy>curBy){
                    if(i==2){
                        nextRy-=dy[i];
                    }
                    else if(i==3){
                        nextBy-=dy[i];
                    }
                }
                else if(curRy<curBy){
                    if(i==2){
                        nextBy-=dy[i];
                    }
                    else if(i==3){
                        nextRy-=dy[i];
                    }
                }
            }
            
            if(nextRx==curRx && nextRy==curRy && nextBx==curBx && nextBy==curBy) continue;
            
            if(!redInHole && !blueInHole && cnt+1<10){
                q.push({{nextRx, nextRy, nextBx, nextBy}, cnt+1});
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j]=='R'){
                rx=i, ry=j;
                map[i][j]='.';
            }
            else if(map[i][j]=='B'){
                bx=i, by=j;
                map[i][j]='.';
            }
            else if(map[i][j]=='O'){
                ox=i, oy=j;
            }
        }
    }
    
    q.push({{rx, ry, bx, by}, 0});
    bfs();
    cout<<ans;
}