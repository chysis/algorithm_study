#include <iostream>
using namespace std;

int DP[21][10001];
int coin[21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N, M;
        cin>>N;
        for(int i=1; i<=N; i++){
            cin>>coin[i];
        }
        
        cin>>M;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(coin[i]>j) DP[i][j]=DP[i-1][j];
                else if(coin[i]==j) DP[i][j]=DP[i-1][j]+1;
                else DP[i][j]=DP[i][j-coin[i]]+DP[i-1][j];
            }
        }
        
        cout<<DP[N][M]<<"\n";
    }
}