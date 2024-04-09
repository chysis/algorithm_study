#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int R, C, T;
int cleaner[2];
int map[51][51];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
vector<pair<pair<int, int>, int>> dust;

int countFineDust(){
    int ans=0;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j]!=-1) ans+=map[i][j];    
        }
    }
    
    return ans;
}

void diffuse(){
    dust.clear();
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j]>0) dust.push_back({{i, j}, map[i][j]});
        }
    }
    
    for(auto a: dust){
        for(int d=0; d<4; d++){
            int nx=a.first.first+dx[d];
            int ny=a.first.second+dy[d];
            
            if(nx>=0 && ny>=0 && nx<R && ny<C && map[nx][ny]!=-1){
                map[nx][ny]+=floor(a.second/5);
                map[a.first.first][a.first.second]-=floor(a.second/5);
            }
        }
    }
}

void clean(){
    // 위쪽 공기청정기 작동
    for(int i=cleaner[0]-1; i>0; i--){
        map[i][0]=map[i-1][0];
    }
    
    for(int i=0; i<C-1; i++){
        map[0][i]=map[0][i+1];
    }
    
    for(int i=0; i<cleaner[0]; i++){
        map[i][C-1]=map[i+1][C-1];
    }
    
    for(int i=C-1; i>1; i--){
        map[cleaner[0]][i]=map[cleaner[0]][i-1];
    }
    
    map[cleaner[0]][1]=0;
        
    // 아래쪽 공기청정기 작동
    for(int i=cleaner[1]+1; i<R-1; i++){
        map[i][0]=map[i+1][0];
    }
    
    for(int i=0; i<C-1; i++){
        map[R-1][i]=map[R-1][i+1];
    }
    
    for(int i=R-1; i>cleaner[1]; i--){
        map[i][C-1]=map[i-1][C-1];
    }
    
    for(int i=C-1; i>1; i--){
        map[cleaner[1]][i]=map[cleaner[1]][i-1];
    }
    
    map[cleaner[1]][1]=0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>R>>C>>T;
    
    int cnt=0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
            if(map[i][j]==-1){
                cleaner[cnt++]=i;
            }
        }
    }
    
    while(T--){
        diffuse();
        clean();
    }
    
    cout<<countFineDust();
}