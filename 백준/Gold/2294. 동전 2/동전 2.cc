#include <iostream>
#include <algorithm>
#define INF (~0U>>2)
using namespace std;

int N, K, arr[101], dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    sort(arr+1, arr+N+1);
    
    for(int i=1; i<=K; i++){
        dp[i]=INF;
    }
    
    for(int i=1; i<=N; i++){
        if(arr[i]>K) continue;
        dp[arr[i]]=1;
        for(int j=arr[i]; j<=K; j++){
            dp[j]=min(dp[j], dp[j-arr[i]]+1);
        }
    }
    
    cout<<(dp[K]==INF ? -1 : dp[K]);
}