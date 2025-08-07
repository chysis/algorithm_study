#include <bits/stdc++.h>
using namespace std;

int N, S, arr[20001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>S;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    sort(arr, arr+N);
    
    int u=lower_bound(arr, arr+N, S)-arr;

    int ans=0;
    for(int i=0; i<u; i++){
        for(int j=0; j<i; j++){
            if(i==j) continue;
            if(arr[i]+arr[j]<=S) ans++;
        }
    }
    cout<<ans;
}