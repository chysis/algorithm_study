#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, arr[250001], dp[250001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true){
        cin>>N;
        if(N==0) break;
        
        for(int i=1; i<=N; i++){
            dp[i]=0;
            cin>>arr[i];
        }
        
        for(int i=1; i<=N; i++){
            dp[i]=max(dp[i-1]+arr[i], arr[i]);
        }
        
        cout<<*max_element(dp+1, dp+N+1)<<"\n";
    }
}