#include <bits/stdc++.h>
using namespace std;

int N, Q, L, R, arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++) cin>>arr[i];
    
    for(int i=2; i<=N; i++) arr[i]+=arr[i-1];
    cin>>Q;
    
    for(int i=0; i<Q; i++){
        cin>>L>>R;
        cout<<arr[R]-arr[L-1]<<"\n";
    }
}