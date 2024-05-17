#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>

#define t5iv tuple<int, int, int, int, vector<char>>
using namespace std;

int N, M, ans=-1;
int rx, ry, bx, by, ox, oy;
char map[11][11];
queue<pair<t5iv, int>> q;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

string fourWay = "UDLR";
vector<char> ansTrack;

void bfs(){
    bool ok=false;
    while(!q.empty()){
        int curRx=get<0>(q.front().first);
        int curRy=get<1>(q.front().first);
        int curBx=get<2>(q.front().first);
        int curBy=get<3>(q.front().first);
        vector<char> curTrack=get<4>(q.front().first);
        int cnt=q.front().second;
        q.pop();

        if(ok){
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
                ans=cnt+1;
                curTrack.push_back(fourWay[i]);
                ansTrack=curTrack;
                ok=true;
            }
            else if(blueInHole) continue;
            
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
                vector<char> nextTrack;
                nextTrack=curTrack;
                nextTrack.push_back(fourWay[i]);
                q.push({{nextRx, nextRy, nextBx, nextBy, nextTrack}, cnt+1});
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
    
    vector<char> track;
    
    q.push({{rx, ry, bx, by, track}, 0});
    bfs();
    cout<<ans<<"\n";
    for(auto a: ansTrack) cout<<a;
}