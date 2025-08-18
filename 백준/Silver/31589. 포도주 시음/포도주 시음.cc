#include <bits/stdc++.h>
using namespace std;

int N, K, arr[300001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    sort(arr, arr+N, greater<int>());
    
    int s=1, e=N-1;
    long long ans=arr[0];
    K--;
    while(K>1){
        ans+=arr[s]-arr[e];
        s++, e--;
        K-=2;
    }
    cout<<ans;
}