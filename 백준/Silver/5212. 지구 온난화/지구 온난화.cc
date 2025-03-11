#include <bits/stdc++.h>
using namespace std;

int R, C, sx=99, sy=99, ex=-1, ey=-1;
char arr[11][11];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>arr[i][j];
        }
    }
    
    vector<pair<int, int>> v;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j]=='X'){
                int temp=0;
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0 || ny<0 || nx>=R || ny>=C) {
                        temp++;
                        continue;
                    }
                    if(arr[nx][ny]=='.') temp++;
                }
                
                if(temp>=3){
                    v.push_back({i, j});
                }
            }
        }
    }
    
    for(auto it: v){
        arr[it.first][it.second]='.';
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j]=='X'){
                sx=min(sx, i);
                sy=min(sy, j);
                ex=max(ex, i);
                ey=max(ey, j);
            }
        }
    }
    
    for(int i=sx; i<=ex; i++){
        for(int j=sy; j<=ey; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}