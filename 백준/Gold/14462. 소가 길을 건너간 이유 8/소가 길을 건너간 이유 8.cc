#include <iostream>
#include <algorithm>
using namespace std;

int leftArr[1001];
int rightArr[1001];
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>leftArr[i];
    }
    
    for(int i=1; i<=N; i++){
        cin>>rightArr[i];
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(abs(leftArr[i]-rightArr[j])<=4){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout<<dp[N][N];
}