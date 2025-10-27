#include <bits/stdc++.h>
using namespace std;

int N, mn, arr[200001], dp[200001]; // dp[i]: i번째까지 추가했을 때 차이의 최댓값

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    dp[0]=0;
    mn=arr[0];
    
    for(int i=1; i<N; i++){
        if(arr[i]<mn) mn=arr[i];
        dp[i]=max(dp[i-1], arr[i]-mn);
    }
    
    for(int i=0; i<N; i++) cout<<dp[i]<<" ";
}