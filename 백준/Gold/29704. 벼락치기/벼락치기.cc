#include <bits/stdc++.h>
using namespace std;

// dp[i][j]: i번째 문제까지 풀었을 때 최대 소요 일수가 j일 때의 최대 가치
int N, T, D, M, dp[1001][1001], sum=0;
pair<int, int> arr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>T;
    for(int i=1; i<=N; i++){
        cin>>D>>M;
        arr[i]={D, M};
        sum+=M;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=T; j++){
            if(arr[i].first>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(arr[i].second+dp[i-1][j-arr[i].first], dp[i-1][j]);
            }
        }
    }
    
    cout<<sum-dp[N][T];
}