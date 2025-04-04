#include <bits/stdc++.h>
using namespace std;

int N, M, arr[31][31], sel[4], ans=-1;

void solve(int cnt, int prev){
    if(cnt==3){
        int temp=0;
        for(int i=0; i<N; i++){
            temp+=max({arr[i][sel[0]], arr[i][sel[1]], arr[i][sel[2]]});   
        }
        ans=max(ans, temp);
        return;
    }
    
    for(int i=prev+1; i<M; i++){
        sel[cnt]=i;
        solve(cnt+1, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    solve(0, -1);
    cout<<ans;
}