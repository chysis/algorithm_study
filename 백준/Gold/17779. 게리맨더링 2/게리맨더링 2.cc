#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, arr[21][21], area[21][21], ans=INF;

void initArea(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            area[i][j]=0;
        }
    }
}

void solve(int x, int y, int d1, int d2){
    if(x+d1+d2>=N || y-d1<0 || y+d2>=N) return;

    pair<int, int> stdPos[4]; // 시작점에서 시계방향으로
    
    stdPos[0]={x, y};
    stdPos[1]={x+d2, y+d2};
    stdPos[2]={x+d2+d1, y+d2-d1};
    stdPos[3]={x+d1, y-d1};
    
    for(int i=0; i<=d2; i++){
        area[x+i][y+i]=5;
        area[stdPos[3].first+i][stdPos[3].second+i]=5;
    }
    for(int i=0; i<=d1; i++){
        area[x+i][y-i]=5;
        area[stdPos[1].first+i][stdPos[1].second-i]=5;
    }
    
    // area 1
    for(int i=0; i<stdPos[3].first; i++){
        for(int j=0; j<=stdPos[0].second; j++){
            if(area[i][j]==5) break;
            area[i][j]=1;
        }
    }
    
    // area 2
    for(int i=0; i<=stdPos[1].first; i++){
        for(int j=stdPos[0].second+1+max(0, i-stdPos[0].first); j<N; j++){
            area[i][j]=2;
        }
    }
    
    // area 3
    for(int i=stdPos[3].first; i<N; i++){
        for(int j=0; j<=stdPos[2].second; j++){
            if(area[i][j]==5) break;
            area[i][j]=3;
        }
    }
    
    // area 4
    for(int i=stdPos[1].first+1; i<N; i++){
        for(int j=stdPos[2].second+max(0, stdPos[2].first-i+1); j<N; j++){
            area[i][j]=4;
        }
    }
        
    int maxPop=0, minPop=INF, sum[6];
    for(int i=0; i<6; i++) sum[i]=0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(area[i][j]==0) sum[5]+=arr[i][j];
            else sum[area[i][j]]+=arr[i][j];
        }
    }
    
    for(int i=1; i<=5; i++){
        if(maxPop<sum[i]) maxPop=sum[i];
        if(minPop>sum[i]) minPop=sum[i];
    }
    
    if(ans>(maxPop-minPop)) ans=maxPop-minPop;
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
    
    for(int i=0; i<N; i++){
        for(int j=1; j<N-1; j++){
            for(int d1=1; d1<=j; d1++){
                for(int d2=1; d2<=N-1-j; d2++){
                    initArea();
                    solve(i, j, d1, d2);
                }
            }
        }
    }
    
    cout<<ans;
}