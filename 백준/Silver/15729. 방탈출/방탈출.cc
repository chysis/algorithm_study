#include <bits/stdc++.h>
using namespace std;

int N, arr[1000001], target[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>target[i];
    
    int ans=0;
    for(int i=0; i<N; i++){
        if(target[i]==arr[i]) continue;
        
        ans++;
        arr[i]=1-arr[i];
        if(i+1<N) arr[i+1]=1-arr[i+1];
        if(i+2<N) arr[i+2]=1-arr[i+2];
    }
    cout<<ans;
}