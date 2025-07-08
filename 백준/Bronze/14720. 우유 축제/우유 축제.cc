#include <bits/stdc++.h>
using namespace std;

int N, arr[1001], dp[1001][3];

int solve(int cur, int now){
    if(cur==N) return 0;
    int& temp=dp[cur][now];
    if(temp!=-1) return temp;
    
    if(arr[cur]==now) temp=max(solve(cur+1, now), solve(cur+1, (now+1)%3)+1);
    else temp=solve(cur+1, now);
    
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
        dp[i][0]=dp[i][1]=dp[i][2]=-1;
    }
    
    cout<<solve(0, 0);
}