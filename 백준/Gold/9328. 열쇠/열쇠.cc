#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int H, W, ans=0;
char map[105][105];
bool key[27];

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[105][105];

queue<pair<int, int>> locked[26];
queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int curX=q.front().first;
        int curY=q.front().second;
        q.pop();
        
        if(map[curX][curY]=='$') {
            ans++;
        }
        
        for(int i=0; i<4; i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            
            if(nx<0 || nx>H+1 || ny<0 || ny>W+1) continue;
            if(visited[nx][ny] || map[nx][ny]=='*') continue;
            
            if(map[nx][ny]>='A' && map[nx][ny]<='Z'){
                if(!key[map[nx][ny]-'A']) locked[map[nx][ny]-'A'].push({nx, ny});
                else{
                    visited[nx][ny]=true;
                    q.push({nx, ny});
                }
            }
            else if(map[nx][ny]>='a' && map[nx][ny]<='z'){
                if(!key[map[nx][ny]-'a']){
                    key[map[nx][ny]-'a']=true;
                    while(!locked[map[nx][ny]-'a'].empty()){
                        auto next=locked[map[nx][ny]-'a'].front();
                        visited[next.first][next.second]=true;
                        q.push({next.first, next.second});
                        locked[map[nx][ny]-'a'].pop();
                    }
                }
                visited[nx][ny]=true;
                q.push({nx, ny});
            }
            else{
                visited[nx][ny]=true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        cin>>H>>W;
        
        for(int i=0; i<=H+1; i++){
            for(int j=0; j<=W+1; j++){
                map[i][j]='.';
            }
        }
        
        for(int i=1; i<=H; i++){
            for(int j=1; j<=W; j++){
                cin>>map[i][j];
            }
        }
        
        string keys;
        cin>>keys;
        if(keys!="0"){
            for(int i=0; i<keys.length(); i++){
                key[keys[i]-'a']=true;
            }
        }
        
        q.push({0, 0});
        bfs();
        
        cout<<ans<<"\n";
        
        ans=0;
        q={};
        for(int i=0; i<26; i++){
            locked[i]={};
        }
        memset(visited, false, sizeof(visited));
        memset(key, false, sizeof(key));
    }
}