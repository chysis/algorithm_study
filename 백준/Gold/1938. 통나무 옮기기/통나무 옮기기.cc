#include <bits/stdc++.h>
using namespace std;

// queue에 중심점과 방향(가로: 0/세로: 1)을 저장하자!

int N, t_cen, t_dir;
char arr[51][51];
queue<tuple<int, int, int>> q; // 횟수, 중심점, 방향
bool visited[51][51][2];

int bfs(){
    while(!q.empty()){
        int cnt=get<0>(q.front());
        int center=get<1>(q.front());
        int dir=get<2>(q.front());
        q.pop();
        
        if(center==t_cen && dir==t_dir){
            return cnt;
        }
        
        int cx=center/N;
        int cy=center%N;
        
        // 상
        if(dir==0){
            if(cx-1>=0 && !visited[cx-1][cy][dir] && arr[cx-1][cy-1]!='1' && arr[cx-1][cy]!='1' && arr[cx-1][cy+1]!='1'){
                q.push({cnt+1, (cx-1)*N+cy, dir});
                visited[cx-1][cy][dir]=true;
            }
        }
        else if(dir==1){
            if(cx-2>=0 && !visited[cx-1][cy][dir] && arr[cx-2][cy]!='1'){
                q.push({cnt+1, (cx-1)*N+cy, dir});
                visited[cx-1][cy][dir]=true;
            }
        }
        
        // 하
        if(dir==0){
            if(cx+1<N && !visited[cx+1][cy][dir] && arr[cx+1][cy-1]!='1' && arr[cx+1][cy]!='1' && arr[cx+1][cy+1]!='1'){
                q.push({cnt+1, (cx+1)*N+cy, dir});
                visited[cx+1][cy][dir]=true;
            }
        }
        else if(dir==1){
            if(cx+2<N && !visited[cx+1][cy][dir] && arr[cx+2][cy]!='1'){
                q.push({cnt+1, (cx+1)*N+cy, dir});
                visited[cx+1][cy][dir]=true;
            }
        }
        
        // 좌
        if(dir==0){
            if(cy-2>=0 && !visited[cx][cy-1][dir] && arr[cx][cy-2]!='1'){
                q.push({cnt+1, cx*N+(cy-1), dir});
                visited[cx][cy-1][dir]=true;
            }
        }
        else if(dir==1){
            if(cy-1>=0 && !visited[cx][cy-1][dir] && arr[cx-1][cy-1]!='1' && arr[cx][cy-1]!='1' && arr[cx+1][cy-1]!='1'){
                q.push({cnt+1, cx*N+(cy-1), dir});
                visited[cx][cy-1][dir]=true;
            }
        }
        
        // 우
        if(dir==0){
            if(cy+2<N && !visited[cx][cy+1][dir] && arr[cx][cy+2]!='1'){
                q.push({cnt+1, cx*N+(cy+1), dir});
                visited[cx][cy+1][dir]=true;
            }
        }
        else if(dir==1){
            if(cy+1<N && !visited[cx][cy+1][dir] && arr[cx-1][cy+1]!='1' && arr[cx][cy+1]!='1' && arr[cx+1][cy+1]!='1'){
                q.push({cnt+1, cx*N+(cy+1), dir});
                visited[cx][cy+1][dir]=true;
            }
        }
        
        // 회전
        if(dir==0){
            if(cx-1>=0 && cx+1<N && !visited[cx][cy][1-dir] && arr[cx-1][cy-1]!='1' && arr[cx-1][cy]!='1' && arr[cx-1][cy+1]!='1' && arr[cx+1][cy-1]!='1' && arr[cx+1][cy]!='1' && arr[cx+1][cy+1]!='1'){
                q.push({cnt+1, cx*N+cy, 1-dir});
                visited[cx][cy][1-dir]=true;
            }
        }
        else if(dir==1){
            if(cy-1>=0 && cy+1<N && !visited[cx][cy][1-dir] && arr[cx-1][cy-1]!='1' && arr[cx][cy-1]!='1' && arr[cx+1][cy-1]!='1' && arr[cx-1][cy+1]!='1' && arr[cx][cy+1]!='1' && arr[cx+1][cy+1]!='1'){
                q.push({cnt+1, cx*N+cy, 1-dir});
                visited[cx][cy][1-dir]=true;
            }
        }
    }
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    
    int center, dir;
    
    // 가로 통나무인지 확인
    for(int i=0; i<N; i++){
        for(int j=0; j<N-2; j++){
            if(arr[i][j]=='B' && arr[i][j+1]=='B' && arr[i][j+2]=='B'){
                center=i*N+j+1;
                dir=0;
            }
            if(arr[i][j]=='E' && arr[i][j+1]=='E' && arr[i][j+2]=='E'){
                t_cen=i*N+j+1;
                t_dir=0;
            }
        }
    }
    
    // 세로 통나무인지 확인
    for(int i=0; i<N-2; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]=='B' && arr[i+1][j]=='B' && arr[i+2][j]=='B'){
                center=(i+1)*N+j;
                dir=1;
            }
            if(arr[i][j]=='E' && arr[i+1][j]=='E' && arr[i+2][j]=='E'){
                t_cen=(i+1)*N+j;
                t_dir=1;
            }
        }
    }

    q.push({0, center, dir});
    cout<<bfs();
}