#include <bits/stdc++.h>
using namespace std;

int N, M, num, arr[31];
bool dp[31][40001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    dp[0][0]=dp[0][arr[0]]=true;
    
    for(int i=1; i<N; i++){
        for(int j=0; j<=40000; j++){
            if(dp[i-1][j]){
                dp[i][j]=true;
                dp[i][abs(j-arr[i])]=true;
                if(j+arr[i]<=40000) dp[i][j+arr[i]]=true;
            }
        }
    }
    
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>num;
        if(dp[N-1][num]) cout<<"Y ";
        else cout<<"N ";
    }
}