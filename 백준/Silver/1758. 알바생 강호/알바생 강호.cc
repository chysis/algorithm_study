#include <bits/stdc++.h>
using namespace std;

int N, arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    sort(arr, arr+N, greater<int>());
    
    long long ans=0;
    for(int i=0; i<N; i++){
        ans+=max(0, (arr[i]-i));
    }
    cout<<ans;
}