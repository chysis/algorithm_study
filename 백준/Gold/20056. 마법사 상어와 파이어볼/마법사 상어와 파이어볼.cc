#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N, M, K;
vector<tuple<int, int, int>> arr[51][51], tempArr[51][51]; // 질량 속력 방향
vector<tuple<int, int, int, int, int>> fbList;
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

void rearrange_arr(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            arr[i][j].clear();
        }
    }
    
    for(int i=0; i<fbList.size(); i++){
        int x=get<0>(fbList[i]);
        int y=get<1>(fbList[i]);
        int mass=get<2>(fbList[i]);
        int speed=get<3>(fbList[i]);
        int dir=get<4>(fbList[i]);
        
        arr[x][y].push_back({mass, speed, dir});
    }
}

void rearrange_list(){
    fbList.clear();
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<arr[i][j].size(); k++){
                int mass=get<0>(arr[i][j][k]);
                int speed=get<1>(arr[i][j][k]);
                int dir=get<2>(arr[i][j][k]);
                fbList.push_back({i, j, mass, speed, dir});
            }
        }
    }
}

void initTempArr(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            tempArr[i][j].clear();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M>>K;
    for(int i=0; i<M; i++){
        int r, c, m, s, d;
        cin>>r>>c>>m>>s>>d;
        fbList.push_back({r, c, m, s, d});
    }
    
    while(K--){
        // fbList 기반으로 파이어볼 이동
        for(int i=0; i<fbList.size(); i++){
            int x=get<0>(fbList[i]);
            int y=get<1>(fbList[i]);
            int mass=get<2>(fbList[i]);
            int speed=get<3>(fbList[i]);
            int dir=get<4>(fbList[i]);
            
            int nx=(x+speed*dx[dir]);
            if(nx<1 || nx>N){
                nx=(nx+1001*N-1)%N+1;
            }
            
            int ny=(y+speed*dy[dir]);
            if(ny<1 || ny>N){
                ny=(ny+1001*N-1)%N+1;
            }
            
            fbList[i]={nx, ny, mass, speed, dir};
            
        }
        
        // arr에 반영
        rearrange_arr();
        
        // arr 기반으로 파이어볼 합체/나누어짐
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(arr[i][j].size()==1){
                    tempArr[i][j].push_back(arr[i][j][0]);
                } else{
                    int massSum=0, speedSum=0, cnt=arr[i][j].size();
                    int oddCnt=0, evenCnt=0;
                    
                    for(int k=0; k<arr[i][j].size(); k++){
                        massSum+=get<0>(arr[i][j][k]);
                        speedSum+=get<1>(arr[i][j][k]);
                        if((get<2>(arr[i][j][k]))%2==0) evenCnt++;
                        else oddCnt++;
                    }
                    
                    if(massSum/5==0) continue;
                    
                    if(oddCnt==0 || evenCnt==0){
                        tempArr[i][j].push_back({massSum/5, speedSum/cnt, 0});
                        tempArr[i][j].push_back({massSum/5, speedSum/cnt, 2});
                        tempArr[i][j].push_back({massSum/5, speedSum/cnt, 4});
                        tempArr[i][j].push_back({massSum/5, speedSum/cnt, 6});
                    } else{
                        tempArr[i][j].push_back({massSum/5, speedSum/cnt, 1});
                        tempArr[i][j].push_back({massSum/5, speedSum/cnt, 3});
                        tempArr[i][j].push_back({massSum/5, speedSum/cnt, 5});
                        tempArr[i][j].push_back({massSum/5, speedSum/cnt, 7});
                    }
                }
            }
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                arr[i][j].clear();
                for(int k=0; k<tempArr[i][j].size(); k++){
                    arr[i][j]=tempArr[i][j];
                }
            }
        }
        
        initTempArr();
        
        // fbList에 반영
        rearrange_list();
    }
    
    int ans=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<arr[i][j].size(); k++){
                ans+=(get<0>(arr[i][j][k]));
            }
        }
    }
    
    cout<<ans;
}