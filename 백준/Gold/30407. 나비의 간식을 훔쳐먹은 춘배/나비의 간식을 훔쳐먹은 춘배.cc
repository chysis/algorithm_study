#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int N, H, D, K, arr[19], maxHp=-1;

void solve(int dep, int hp, int dist, int surpDep){
    if(dep==N){
        maxHp=max(maxHp, hp);
        return;
    }
    
    if(hp<=0) return;
    
    if(surpDep>=0 && dep==surpDep){
        // 놀래키기
        solve(dep+1, hp-max(0, arr[dep]-dist), dist, surpDep);
    }else if(surpDep>=0 && dep-1==surpDep){
        // 무효화, 네발로 걷기
        solve(dep+1, hp, dist+K, surpDep);
    }else{
        int dmg=max(0, arr[dep]-dist);
        solve(dep+1, hp-dmg/2, dist, surpDep); // 웅크리기
        
        int dmgWalk=max(0, arr[dep]-dist-K);
        solve(dep+1, hp-dmgWalk, dist+K, surpDep); // 걷기 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>H>>D>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    solve(0, H, D, -1);
    for(int i=0; i<N-1; i++){
        solve(0, H, D, i);
    }
    cout<<(maxHp<=0 ? -1 : maxHp);
}