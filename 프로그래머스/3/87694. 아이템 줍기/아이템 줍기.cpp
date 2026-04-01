#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int arr[102][102];
bool visited[102][102];
queue<tuple<int, int, int>> q;

// 사각형 내부로 들어가면 안 됨
// 가장자리 위에만 타고 다녀야 함
// 주어진 좌표는 2차원 배열에서 좌측 상단과 우측 하단으로 생각
// 좌표를 그대로 사용하니 변의 길이 1일 때는 선을 따라가지 않고 그냥 뚫고 지나가는 문제 발생 -> 좌표를 2배로 늘려서 계산
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 직사각형 테두리는 1, 내부는 2로 표시
    for(int i=0; i<rectangle.size(); i++){
        int x1=rectangle[i][0]*2;
        int y1=rectangle[i][1]*2;
        int x2=rectangle[i][2]*2;
        int y2=rectangle[i][3]*2;
        
        for(int x=x1+1; x<x2; x++){
            for(int y=y1+1; y<y2; y++){
                if(arr[x][y]!=2){
                    // 사각형 내부는 덧칠해짐
                    arr[x][y]=2;
                }
            }
        }
        
        for(int a=1; a<=12; a++){
            for(int b=1; b<=12; b++){
                cout<<arr[a][b]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        
        for(int x=x1; x<=x2; x++){
            if(arr[x][y1]==0) arr[x][y1]=1;
            if(arr[x][y2]==0) arr[x][y2]=1;
        }
        
        for(int y=y1; y<=y2; y++){
            if(arr[x1][y]==0) arr[x1][y]=1;
            if(arr[x2][y]==0) arr[x2][y]=1;
        }
    }
    
    // bfs
    q.push({characterX*2, characterY*2, 0});
    visited[characterX*2][characterY*2]=true;
    
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int cnt=get<2>(q.front());
        q.pop();
        
        if(x==itemX*2 && y==itemY*2){
            return cnt/2;
        }
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>100 || ny>100) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny]!=1) continue;
            
            q.push({nx, ny, cnt+1});
            visited[nx][ny]=true;
        }
    }
    
    return 0;
}