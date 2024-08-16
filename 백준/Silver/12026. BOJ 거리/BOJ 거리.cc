#include <iostream>
#include <cmath>
#include <algorithm>

#define INF 987654321
using namespace std;

char arr[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++){
        dp[i]=INF;
    }
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    dp[0]=0;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(arr[i]=='B' && arr[j]!='O') continue;
            else if(arr[i]=='O' && arr[j]!='J') continue;
            else if(arr[i]=='J' && arr[j]!='B') continue;
            
            dp[j]=min(dp[j], dp[i]+(int)pow(j-i, 2));
        }
    }
    
    if(dp[N-1]==INF) cout<<-1;
    else cout<<dp[N-1];
}