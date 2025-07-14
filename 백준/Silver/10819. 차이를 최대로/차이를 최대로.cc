#include <bits/stdc++.h>
using namespace std;

int N, arr[9], sel[9], ans=-1;
bool visited[9];

void solve(int cnt){
    if(cnt==N){
        int temp=0;
        for(int i=0; i<N-1; i++){
            temp+=abs(arr[sel[i]]-arr[sel[i+1]]);
        }
        ans=max(ans, temp);
        return;
    }
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i]=true;
            sel[cnt]=i;
            solve(cnt+1);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    solve(0);
    cout<<ans;
}