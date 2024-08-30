#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int M, S, sx, sy;
vector<int> map[5][5];
bool smell[5][5][101];
int dx[9]={0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9]={0, -1, -1, 0, 1, 1, 1, 0, -1};

int dx4[4]={-1, 0, 1, 0};
int dy4[4]={0, -1, 0, 1};
bool visited[5][5];

vector<int> solve(){
    vector<int> ans={0, 0, 0};
    bool visited[5][5];
    int maxFish=-1;
    
    int temp[3];
    for(int i=0; i<4; i++){
        int nx1=sx+dx4[i];
        int ny1=sy+dy4[i];
        if(nx1<1 || ny1<1 || nx1>4 || ny1>4) continue;
        temp[0]=i;
        
        for(int j=0; j<4; j++){
            int nx2=nx1+dx4[j];
            int ny2=ny1+dy4[j];
            if(nx2<1 || ny2<1 || nx2>4 || ny2>4) continue;
            temp[1]=j;
            
            for(int k=0; k<4; k++){
                int nx3=nx2+dx4[k];
                int ny3=ny2+dy4[k];
                if(nx3<1 || ny3<1 || nx3>4 || ny3>4) continue;
                temp[2]=k;
                
                int fish=0;
                int curX=sx, curY=sy;
                memset(visited, false, sizeof(visited));
                for(int w=0; w<3; w++){
                    curX+=dx4[temp[w]];
                    curY+=dy4[temp[w]];
                    if(!visited[curX][curY]){
                        fish+=map[curX][curY].size();
                        visited[curX][curY]=true;
                    }
                }
                
                if(fish>maxFish){
                    maxFish=fish;
                    ans.clear();
                    ans.push_back(temp[0]);
                    ans.push_back(temp[1]);
                    ans.push_back(temp[2]);
                }
            }
        }
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>M>>S;
    for(int i=0; i<M; i++){
        int fx, fy, d;
        cin>>fx>>fy>>d;
        map[fx][fy].push_back(d);
    }
    cin>>sx>>sy;
    
    for(int a=1; a<=S; a++){
        // 복제될 map
        vector<int> copyMap[5][5];
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                copyMap[i][j]=map[i][j];
            }
        }
        
        // 물고기 이동
        vector<int> nextMap[5][5];
        
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                for(int k=0; k<map[i][j].size(); k++){
                    int dir=-1, nx, ny;
                    for(int d=0; d<8; d++){
                        // 45도 반시계 회전
                        int tempDir=map[i][j][k]-d;
                        if(tempDir<1) tempDir+=8;
                        int x=i+dx[tempDir];
                        int y=j+dy[tempDir];
                        
                        if(x<1 || y<1 || x>4 || y>4) continue;
                        if(x==sx && y==sy) continue;
                        if(smell[x][y][a-1] || smell[x][y][a-2]) continue;
                        
                        dir=tempDir, nx=x, ny=y;
                        break;
                    }
                    
                    if(dir!=-1){
                        nextMap[nx][ny].push_back(dir);
                    } else nextMap[i][j].push_back(map[i][j][k]);
                }
            }
        }
        
        // cout<<"shark: "<<sx<<" "<<sy<<"\n";
        
        // cout<<"fish moving "<<a<<"\n";
        // for(int i=1; i<=4; i++){
        //     for(int j=1; j<=4; j++){
        //         cout<<nextMap[i][j].size()<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        
        // map 업데이트
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                map[i][j]=nextMap[i][j];
            }
        }
        
        // 사전 순으로 가장 앞서는 상어 이동 경로 구하기
        vector<int> ans=solve();
        // cout<<"SHARK "<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
         
        for(int i=0; i<3; i++){
            sx+=dx4[ans[i]];
            sy+=dy4[ans[i]];

            if(map[sx][sy].size()>0){
                smell[sx][sy][a]=true;
            }
            map[sx][sy].clear();
        }
        
        // cout<<"shark: "<<sx<<" "<<sy<<"\n";
        
        // 2턴 지난 물고기 냄새는 사라짐
        if(a>=3){
            for(int i=1; i<=4; i++){
                for(int j=1; j<=4; j++){
                    smell[i][j][a-2]=false;
                }
            }
        }
        
        // 복제 마법 완료
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                map[i][j].insert(map[i][j].end(), copyMap[i][j].begin(), copyMap[i][j].end());
            }
        }
        
        // cout<<"after copy "<<a<<"\n";
        // for(int i=1; i<=4; i++){
        //     for(int j=1; j<=4; j++){
        //         cout<<map[i][j].size()<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        
        // cout<<"smell "<<a<<"\n";
        // for(int i=1; i<=4; i++){
        //     for(int j=1; j<=4; j++){
        //         cout<<(smell[i][j][a] || smell[i][j][a-1])<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
    }
    
    int sum=0;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            sum+=map[i][j].size();
        }
    }
    
    cout<<sum;
}