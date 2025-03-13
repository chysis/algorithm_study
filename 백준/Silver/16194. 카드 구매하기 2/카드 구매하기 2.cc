#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, arr[1001], dp[1001]; // dp[x]: 카드 x개를 갖기 위해 지불하는 최소 금액

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        dp[i]=INF;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i]=min({dp[i], arr[i], arr[j]+dp[i-j]});
        }
    }
    
    cout<<dp[N];
}