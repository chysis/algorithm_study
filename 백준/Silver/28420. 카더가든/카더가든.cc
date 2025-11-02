#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, A, B, C, arr[301][301], sum=INF;
bool car[3][301][301];

void solve(int x, int y, int opt){
    int temp=0;
    if(opt==0){
        for(int i=0; i<A; i++){
            for(int j=0; j<B+C; j++){
                if(car[opt][i][j]){
                    temp+=arr[x+i][y+j];
                }
            }
        }
    } else if(opt==1){
        for(int i=0; i<A+B; i++){
            for(int j=0; j<A+C; j++){
                if(car[opt][i][j]){
                    temp+=arr[x+i][y+j];
                }
            }
        }
    } else if(opt==2){
        for(int i=0; i<A+C; i++){
            for(int j=0; j<A+B; j++){
                if(car[opt][i][j]){
                    temp+=arr[x+i][y+j];
                }
            }
        }
    }
    
    sum=min(sum, temp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>A>>B>>C;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    // 1. a*(b+c)
    for(int i=0; i<A; i++){
        for(int j=0; j<B+C; j++){
            car[0][i][j]=true;
        }
    }
    
    // 2. (a+b)*(a+c)
    for(int i=0; i<A; i++){
        for(int j=0; j<C; j++){
            car[1][i][j]=true;
        }
    }
    
    for(int i=A; i<A+B; i++){
        for(int j=C; j<A+C; j++){
            car[1][i][j]=true;
        }
    }
    
    // 3. (a+c)*(a+b)
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            car[2][i][j]=true;
        }
    }
    
    for(int i=A; i<A+C; i++){
        for(int j=B; j<A+B; j++){
            car[2][i][j]=true;
        }
    }
    
    // 1번 대입
    for(int i=0; i<=N-A; i++){
        for(int j=0; j<=M-(B+C); j++){
            solve(i, j, 0);
        }
    }
    
    // 2번 대입
    for(int i=0; i<=N-(A+B); i++){
        for(int j=0; j<=M-(A+C); j++){
            solve(i, j, 1);
        }
    }
    
    // 3번 대입
    for(int i=0; i<=N-(A+C); i++){
        for(int j=0; j<=M-(A+B); j++){
            solve(i, j, 2);
        }
    }
    
    cout<<sum;
}