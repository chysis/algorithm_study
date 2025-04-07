#include <bits/stdc++.h>
using namespace std;

int N, hp[21], happy[21], ans;

void solve(int cnt, int curHp, int curHappy){
    if(cnt==N){
        ans=max(ans, curHappy);
        return;
    }

    solve(cnt+1, curHp, curHappy);
    
    if(curHp-hp[cnt]>0) solve(cnt+1, curHp-hp[cnt], curHappy+happy[cnt]);
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
    
    solve(0, 100, 0);
    cout<<ans;
}