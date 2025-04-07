#include <bits/stdc++.h>
using namespace std;

int N, hp[21], happy[21], dp[21][101];

int solve(int cnt, int curHp){
    if(dp[cnt][curHp]) return dp[cnt][curHp];
    if(cnt==N) return 0;
    
    int& temp=dp[cnt][curHp];

    if(curHp-hp[cnt]>0) temp=solve(cnt+1, curHp-hp[cnt])+happy[cnt];
    
    int temp2=solve(cnt+1, curHp);
    temp=max(temp, temp2);
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>hp[i];
    }
    
    for(int i=0; i<N; i++){
        cin>>happy[i];
    }
    
    cout<<solve(0, 100);
}