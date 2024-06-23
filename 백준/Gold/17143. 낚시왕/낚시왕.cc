#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, M;
vector<tuple<int, int, int>> map[101][101]; // 속력 이동방향 크기

int dx[4]={-1, 1, 0, 0}; 
int dy[4]={0, 0, 1, -1};

bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b){
    return (get<2>(a))>(get<2>(b));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>R>>C>>M;
    for(int i=0; i<M; i++){
        int r, c, s, d, z;
        cin>>r>>c>>s>>d>>z;
        
        map[r][c].push_back({s, d-1, z});
    }
    
    int ans=0;
    
    for(int cnt=1; cnt<=C; cnt++){
        // 가장 가까운 상어 잡기
        for(int i=1; i<=R; i++){
            if(map[i][cnt].size()>0){
                ans+=get<2>(map[i][cnt][0]);
                map[i][cnt].clear();
                break;
            }
        }
        
        // 상어 이동
        vector<tuple<int, int, int>> tempMap[101][101];
        
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(map[i][j].size()==0) continue;
                
                auto cur=map[i][j][0];
                int speed=get<0>(cur);
                int dir=get<1>(cur);
                
                int nx=i+dx[dir]*speed;
                int ny=j+dy[dir]*speed;
                
                if(nx<1 || nx>R){
                    while(true){
                        if(nx>=1 && nx<=R) break;
                        
                        if(dir==0){ // nx<1
                            dir=1;
                            nx=1+(1-nx);
                        } else if(dir==1){ // nx>R
                            dir=0;
                            nx=R-(nx-R);
                        }
                    }
                }
                
                speed=get<0>(cur);
                
                if(ny<1 || ny>C){
                    while(true){
                        if(ny>=1 && ny<=C) break;
                        
                        if(dir==3){ // ny<1
                            dir=2;
                            ny=1+(1-ny);
                        } else if(dir==2){ // ny>C
                            dir=3;
                            ny=C-(ny-C);
                        }
                    }
                }
                
                tempMap[nx][ny].push_back({speed, dir, get<2>(cur)});
            }
        }
        
        // 상어 여러 마리 들어간 경우
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(tempMap[i][j].size()>1){
                    sort(tempMap[i][j].begin(), tempMap[i][j].end(), comp);
                    tuple<int, int, int> tempShark=tempMap[i][j][0];
                    
                    tempMap[i][j].clear();
                    tempMap[i][j].push_back(tempShark);
                }
            }
        }
        
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                map[i][j]=tempMap[i][j];
            }
        }
    }
    
    cout<<ans;
}