#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

// dp[0][j]: 원소를 지우지 않고 j번째로 끝나는 구간의 최대 합
// dp[1][j]: 원소를 하나 지우고 j번째로 끝나는 구간의 최대 합
int N, arr[100001], dp[2][100001], maxVal=-INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        dp[0][i]=dp[1][i]=-INF;
        cin>>arr[i];
        maxVal=max(maxVal, arr[i]);
    }
    
    if(maxVal<0){
        cout<<maxVal;
        return 0;
    }
    
    // 제거하지 않는 경우
    for(int i=1; i<=N; i++){
        // 이전까지 제거하지 않고 + 현재 원소(이어서)
        // 현재 원소에서 시작
        dp[0][i]=max({dp[0][i], dp[0][i-1]+arr[i], arr[i]});
    }
    
    // 최대 하나 제거하는 경우
    for(int i=1; i<=N; i++){
        // 이전까지 하나 이미 제거한 경우 + 현재 원소(이어서)
        // 이전까지 제거하지 않고 + 현재 원소 제거
        dp[1][i]=max({dp[1][i], dp[1][i-1]+arr[i], dp[0][i-1]});
    }
    
    int ans=-INF;
    for(int i=1; i<=N; i++) ans=max({ans, dp[0][i], dp[1][i]});
    cout<<ans;
}