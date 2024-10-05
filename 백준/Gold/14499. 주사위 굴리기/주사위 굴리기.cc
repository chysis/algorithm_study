#include <iostream>
using namespace std;

int N, M, x, y, K;
int map[21][21], dice[6];
int dx[5]={0, 0, 0, -1, 1};
int dy[5]={0, 1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M>>x>>y>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<K; i++){
        int cmd;
        cin>>cmd;
        
        int nx=x+dx[cmd];
        int ny=y+dy[cmd];
        
        if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
        
        if(cmd==1){
            int temp=dice[4];
            dice[4]=dice[2], dice[2]=dice[5], dice[5]=dice[0], dice[0]=temp;
        } else if(cmd==2){
            int temp=dice[0];
            dice[0]=dice[5], dice[5]=dice[2], dice[2]=dice[4], dice[4]=temp;
        } else if(cmd==3){
            int temp=dice[1];
            dice[1]=dice[2], dice[2]=dice[3], dice[3]=dice[0], dice[0]=temp;
        } else{
            int temp=dice[0];
            dice[0]=dice[3], dice[3]=dice[2], dice[2]=dice[1], dice[1]=temp;
        }
        
        if(map[nx][ny]==0){
            map[nx][ny]=dice[2];
        } else{
            dice[2]=map[nx][ny];
            map[nx][ny]=0;
        }
        
        cout<<dice[0]<<"\n";
        x=nx, y=ny;
    }
}