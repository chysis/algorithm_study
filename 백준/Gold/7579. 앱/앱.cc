#include <iostream>
#include <algorithm>
using namespace std;

int N, M, totalCost=0;
int mem[101], cost[101], dp[101][10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        cin>>mem[i];
    }
    
    for(int i=1; i<=N; i++){
        cin>>cost[i];
        totalCost+=cost[i];
    }
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=totalCost; j++){
            if(j>=cost[i]){
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-cost[i]]+mem[i]);
            } else{
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
            }
        }
    }
    
    for(int i=0; i<=totalCost; i++){
        if(dp[N][i]>=M){
            cout<<i;
            break;
        }
    }
}