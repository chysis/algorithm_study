#include <bits/stdc++.h>
using namespace std;

int N, Q, X, Y, arr[100001], sum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    for(int i=2; i<=N; i++){
        if(arr[i]<arr[i-1]) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
    }
    
    cin>>Q;
    for(int i=0; i<Q; i++){
        cin>>X>>Y;
        if(X==Y) cout<<0<<"\n";
        else cout<<sum[Y]-sum[X]<<"\n";
    }
}