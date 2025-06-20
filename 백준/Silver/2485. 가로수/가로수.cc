#include <bits/stdc++.h>
using namespace std;

int N, arr[100001], diff[100001];

int gcd(int a, int b){
    return (a%b) ? gcd(b, a%b) : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    for(int i=1; i<N; i++) diff[i-1]=arr[i]-arr[i-1];
    
    int temp=gcd(diff[0], diff[1]);
    for(int i=2; i<N-1; i++) temp=gcd(temp, diff[i]);
    
    int ans=0;
    for(int i=0; i<N-1; i++){
        ans+=(diff[i]/temp)-1;
    }
    cout<<ans;
}