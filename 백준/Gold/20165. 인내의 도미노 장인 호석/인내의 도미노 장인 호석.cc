#include <bits/stdc++.h>
using namespace std;

int N, M, R, X, Y, arr[101][101], score=0;
char D;
bool fallen[101][101];
int dx[4]={0, 0, 1, -1}; // 동서남북
int dy[4]={1, -1, 0, 0};

void attack(int x, int y, int dir){
    if(fallen[x][y]) return;
    
    int cx=x, cy=y, reach=arr[x][y];
    
    while(true){
        if(cx<=0 || cy<=0 || cx>N || cy>M) break;
        if(reach<=0) break;
        
        if(!fallen[cx][cy]){
            fallen[cx][cy]=true;
            score++;
            reach=max(reach, arr[cx][cy]); // 넘어뜨릴 개수를 연속해서 갱신
        }
        
        cx+=dx[dir];
        cy+=dy[dir];
        reach--;
    }
}

void defense(int x, int y){
    fallen[x][y]=false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>R;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<R; i++){
        cin>>X>>Y>>D; // 공격
        if(D=='E') attack(X, Y, 0);
        else if(D=='W') attack(X, Y, 1);
        else if(D=='S') attack(X, Y, 2);
        else attack(X, Y, 3);
        
        cin>>X>>Y; // 수비
        defense(X, Y);
    }
    
    cout<<score<<"\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout<<(fallen[i][j] ? "F" : "S")<<" ";
        }
        cout<<"\n";
    }
}