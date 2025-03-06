#include <bits/stdc++.h>
using namespace std;

int N, X, Y;
int board[101][101];

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>X>>Y;
        for(int a=X; a<X+10; a++){
            for(int b=Y; b<Y+10; b++){
                board[a][b]=1;
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(board[i][j]==1){
                int temp=0;
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(board[nx][ny]==0){
                        temp++;
                    }
                }
                
                ans+=temp;
            }
        }
    }
    
    cout<<ans;
}