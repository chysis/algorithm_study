#include <bits/stdc++.h>
using namespace std;

int N, M, maxSize[16][16], ans=1;
char arr[16][16];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            maxSize[i][j]=-1;
        }
    }
    
    // 칸마다 놓을 수 있는 십자가의 최대 크기 계산
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]=='.') continue;
            
            for(int size=1; ; size++){
                // 십자가 크기가 size가 될 수 있는지 확인
                if(i-size<0 || j-size<0 || i+size>=N || j+size>=M){
                    maxSize[i][j]=max(maxSize[i][j],  size-1);
                    break;
                }
                
                if(arr[i-size][j]!='#' || arr[i][j-size]!='#' || arr[i+size][j]!='#' || arr[i][j+size]!='#'){
                    maxSize[i][j]=max(maxSize[i][j],  size-1);
                    break;
                }
            }
        }
    }
    
    // 두 칸을 선택하고, 만들 수 있는 가장 큰 넓이의 곱 구하기
    for(int i=0; i<N*M; i++){
        for(int j=i+1; j<N*M; j++){
            int x1=i/M, x2=j/M, y1=i%M, y2=j%M;
            if(maxSize[x1][y1]==-1 || maxSize[x2][y2]==-1) continue;
            
            for(int a=0; a<=maxSize[x1][y1]; a++){
                for(int b=0; b<=maxSize[x2][y2]; b++){
                    if(x1==x2){
                        // 세로 선끼리 겹치는 경우
                        if(abs(y1-y2)<=a+b) break;
                    }else if(y1==y2){
                        // 가로 선끼리 겹치는 경우
                        if(abs(x1-x2)<=a+b) break;
                    }else{
                        // x, y 모두 다르면 날개 진행 방향끼리는 겹치지 않지만 날개 중간을 뚫고 지나갈 수 있음
                        // 세로로 교차하는 경우와 가로로 교차하는 경우를 고려
                        bool isOverlap=(abs(x1-x2)<=a && abs(y1-y2)<=b) || (abs(x1-x2)<=b && abs(y1-y2)<=a);
                        if(isOverlap) break;
                    }
                    
                    int a_size=4*a+1, b_size=4*b+1;
                    ans=max(ans, a_size*b_size);
                }
            }
        }
    }
    
    cout<<ans;
}