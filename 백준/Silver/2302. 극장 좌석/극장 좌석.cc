#include <bits/stdc++.h>
using namespace std;

int N, M, num, dp[41];
bool isFixed[41];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>num;
        isFixed[num]=true;
    }
    
    dp[0]=1, dp[1]=1;
    for(int i=2; i<=N; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    
    int ans=1, prev=0;
    for(int i=1; i<=N; i++){
        if(isFixed[i]){
            ans*=dp[i-1-prev];
            prev=i;
        }
    }
    ans*=dp[N-prev];
    
    cout<<ans;
}