#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, K, dp[21][2];
pair<int, int> arr[21];

int solve(int cur, int jump){
    if(cur==N-1) return 0;
    
    int& temp=dp[cur][jump];
    if(temp!=INF) return temp;
    
    if(cur<N-1) temp=min(temp, solve(cur+1, jump)+arr[cur].first);
    if(cur<N-2) temp=min(temp, solve(cur+2, jump)+arr[cur].second);
    if(jump==0 && cur<N-3) temp=min(temp, solve(cur+3, 1)+K);
    
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin>>a>>b;
        arr[i]={a, b};
    }
    cin>>K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<2; j++){
            dp[i][j]=INF;
        }
    }

    cout<<solve(0, 0);
}