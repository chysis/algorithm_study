#include <iostream>
#include <algorithm>
using namespace std;

int N, K, ans=0;
int arr[21], dp[21];

void solve(int cnt, int sati, int energy){
    if(cnt==N) {
        ans=max(ans, energy);
        return;
    }
    
    // 안 먹으면?
    if(sati==0) solve(cnt+1, sati, energy);
    
    // 먹으면?
    if(sati+arr[cnt]>=K) solve(cnt+1, 0, energy+sati+arr[cnt]-K);
    else solve(cnt+1, sati+arr[cnt], energy);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    solve(0, 0, 0);
    cout<<ans;
}