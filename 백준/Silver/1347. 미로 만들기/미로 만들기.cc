#include <iostream>
using namespace std;

int x=54, y=54, dir=0;
char map[110][110];
bool visited[110][110];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    string str;
    cin>>str;
    
    for(int i=0; i<110; i++){
        for(int j=0; j<110; j++){
            map[i][j]='#';
        }
    }
    
    map[x][y]='.';
    visited[x][y]=true;
    
    for(int i=0; i<str.length(); i++){
        if(str[i]=='F'){
            x+=dx[dir];
            y+=dy[dir];
            map[x][y]='.';
            visited[x][y]=true;
        } else if(str[i]=='L'){
            dir--;
            if(dir<0) dir=3;
        } else if(str[i]=='R'){
            dir++;
            if(dir>3) dir=0;
        }
    }
    
    int minX=200, maxX=-1, minY=200, maxY=-1;
    for(int i=0; i<110; i++){ 
        for(int j=0; j<110; j++){
            if(visited[i][j]){
                minX=min(minX, i);
                maxX=max(maxX, i);
                minY=min(minY, j);
                maxY=max(maxY, j);
            }
        }
    }
    
    for(int i=minX; i<=maxX; i++){
        for(int j=minY; j<=maxY; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}