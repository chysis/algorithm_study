#include <iostream>
#include <algorithm>

#define DIV 1000000000
using namespace std;

int dp[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    
    dp[0]=0, dp[1]=1;
    
    if(N>0) cout<<1<<"\n";
    else if(N==0) cout<<0<<"\n";
    else{
        if(abs(N)%2==0) cout<<-1<<"\n";
        else cout<<1<<"\n";
    }
    
    if(N==0) cout<<0;
    else if(N==1) cout<<1;
    else if(N==-1) cout<<1;
    else {
        for(int i=2; i<=abs(N); i++){
            dp[i]=(dp[i-1]+dp[i-2])%DIV;
        }
        
        cout<<dp[abs(N)];
    }
}