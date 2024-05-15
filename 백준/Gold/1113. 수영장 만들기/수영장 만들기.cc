#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int map[51][51];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

bool visited[51][51];
int water[51][51];
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin>>c;
            map[i][j]=c-'0';
        }
    }
    
    int ans=0;
    for(int w=2; w<=9; w++){
        memset(visited, false, sizeof(visited));
        memset(water, 0, sizeof(water));
        
        int bfsCnt=1;
        for(int i=1; i<N-1; i++){
            for(int j=1; j<M-1; j++){
                if(map[i][j]<w && !visited[i][j]){
                    visited[i][j]=true;
                    q.push({i, j});
                    
                    bool flag=true;
                    while(!q.empty()){
                        auto cur=q.front();
                        q.pop();
                        
                        water[cur.first][cur.second]=bfsCnt;
                        
                        for(int k=0; k<4; k++){
                            int nx=cur.first+dx[k];
                            int ny=cur.second+dy[k];
                            
                            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                            if(map[nx][ny]>=w) continue;
                            if(visited[nx][ny]) continue;
                            if(nx==0 || ny==0 || nx==N-1 || ny==M-1){
                                flag=false;
                                break;
                            }
                            
                            visited[nx][ny]=true;
                            q.push({nx, ny});
                        }
                        
                        if(!flag) break;
                    }
                    
                    q={};
                
                    if(!flag){
                        for(int i=0; i<N; i++){
                            for(int j=0; j<M; j++){
                                if(water[i][j]==bfsCnt) water[i][j]=0;
                            }
                        }
                        memset(visited, false, sizeof(visited));
                    }
                    
                    bfsCnt++;
                }
            }
        }
        
        // cout<<"cur: "<<w<<"\n";
        
        // for(int i=0; i<N; i++){
        //     for(int j=0; j<M; j++){
        //         cout<<water[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(water[i][j]>0) ans++;
            }
        }
    }
    
    cout<<ans;
}