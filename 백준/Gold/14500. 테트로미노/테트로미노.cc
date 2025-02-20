#include <iostream>
using namespace std;

int N, M, map[501][501], ans=0;
int len[5]={2, 1, 8, 4, 4};
int dx[5][10][3]={
    {
        {0, 0, 0},
        {1, 2, 3}
    }, 
    {
        {0, 1, 1}
    }, 
    {
        {1, 2, 2},
        {1, 2, 2},
        {-1, -1, -1},
        {0, 0, 1},
        {-1, -2, -2},
        {0, 1, 2},
        {1, 1, 1},
        {0, 0, -1}
    }, 
    {
        {1, 1, 2},
        {1, 1, 2},
        {0, 1, 1},
        {0, -1, -1}
    },
    {
        {0, 0, 1},
        {0, 0, -1},
        {1, 2, 1},
        {1, 2, 1}
    }
};

int dy[5][10][3]={
    {
        {1, 2, 3},
        {0, 0, 0}
    },
    {
        {1, 1, 0}
    },
    {
        {0, 0, 1},
        {0, 0, -1},
        {0, 1, 2},
        {1, 2, 2},
        {0, 0, 1},
        {1, 1, 1},
        {0, 1, 2},
        {1, 2, 2}
    },
    {
        {0, 1, 1},
        {0, -1, -1},
        {1, 1, 2},
        {1, 1, 2}
    },
    {
        {1, 2, 1},
        {1, 2, 1},
        {0, 0, 1},
        {0, 0, -1}
    }
};

void solve(int x, int y){
    for(int i=0; i<5; i++){
        for(int j=0; j<len[i]; j++){
            int temp=map[x][y];
            for(int dir=0; dir<3; dir++){
                int nx=x+dx[i][j][dir];
                int ny=y+dy[i][j][dir];
                if(nx<0 || ny<0 || nx>=N || ny>=M) break;
                
                temp+=map[nx][ny];
            }
            
            ans=max(ans, temp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            solve(i, j);
        }
    }
    
    cout<<ans;
}