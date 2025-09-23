#include <bits/stdc++.h>
using namespace std;

int N, arr[1001], dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    for(int i=0; i<N; i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]) dp[i]=max(dp[i], dp[j]+1);
        }
    }
    cout<<*max_element(dp, dp+N);
}