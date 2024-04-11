#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

char map[13][7];
bool visited[13][7];
queue<pair<pair<int, int>, int>> q;
queue<pair<int, int>> temp;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int temp_cnt=0;

void gravity(){
    bool isExist[6];
    for(int i=0; i<6; i++){
        bool flag=false;
        for(int j=0; j<12; j++){
            if(map[j][i]!='.'){
                flag=true;
                break;
            }
        }
        isExist[i]=flag;
    }
    
    for(int i=0; i<6; i++){
        if(!isExist[i]) continue;
        for(int j=11; j>=0; j--){
            if(map[j][i]=='.') continue;
            int tmp=j;
            
            while(true){
                if(tmp==11 || map[tmp+1][i]!='.') break;
                map[tmp+1][i]=map[tmp][i];
                map[tmp][i]='.';
                tmp++;
            }
        }
    }
}

void dfs(char color, int x, int y){
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<12 && ny>=0 && ny<6 && map[nx][ny]==color && !visited[nx][ny]){
            temp_cnt++;
            temp.push({nx, ny});
            visited[nx][ny]=true;
            dfs(color, nx, ny);
        }
    }
}

int main()
{
    int ans=0;
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cin>>map[i][j];
        }
    }
    int count=0;
    while(true){
        memset(visited, false, sizeof(visited));
        char now;
        bool flag=false;
        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                if(map[i][j]!='.' && !visited[i][j]){
                    now=map[i][j];
                    temp_cnt=1;
                    visited[i][j]=true;
                    temp.push({i, j});
                    dfs(now, i, j);
                    
                    if(temp_cnt>=4){
                        flag=true;
                        while(!temp.empty()){
                            auto a=temp.front();
                            map[a.first][a.second]='.';
                            temp.pop();
                        }
                    }
                    else{
                        while(!temp.empty()) temp.pop();
                    }
                }
            }
        }
        gravity();
        if(flag) ans++;
        else break;
    }
    cout<<ans;
}