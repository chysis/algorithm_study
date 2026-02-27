#include <bits/stdc++.h>
using namespace std;

int N, arr[1000001], ans=-1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    sort(arr, arr+N);
    
    for(int i=N-1; i>=2; i--){
        if(arr[i]>=arr[i-1]+arr[i-2]) continue;
        if(ans>=arr[i]+arr[i-1]+arr[i-2]) break;
        
        ans=max(ans, arr[i]+arr[i-1]+arr[i-2]);
    }
    
    cout<<ans;
}
