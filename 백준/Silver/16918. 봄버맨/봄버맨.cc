#include <bits/stdc++.h>
using namespace std;

int R, C, N, cnt=2, ttl[201][201]; // 설치된 시각
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
char arr[201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C>>N;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>arr[i][j];
            ttl[i][j]=-1;
            
            if(arr[i][j]=='O'){
                ttl[i][j]=0;
            }
        }
    }
    
    while(true){
        if(cnt>N) break; // N초까지는 동작한 뒤 break
        
        // 짝수 초에 설치, 홀수 초에 폭발
        if(cnt%2==0){
            for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                    if(ttl[i][j]==-1){
                        ttl[i][j]=cnt;
                        arr[i][j]='O';
                    }
                }
            }
        } else{
            vector<pair<int, int>> temp;
            
            for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                    if(cnt-ttl[i][j]==3){ // 3초 전에 설치됐으면 폭발
                        temp.push_back({i, j});
                    }
                }
            }
            
            for(auto it: temp){
                int x=it.first;
                int y=it.second;
                arr[x][y]='.';
                ttl[x][y]=-1;
                
                for(int i=0; i<4; i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
                    arr[nx][ny]='.';
                    ttl[nx][ny]=-1;
                }
            }
            
            temp.clear();
        }
        
        cnt++;
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}