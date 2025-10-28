#include <bits/stdc++.h>
using namespace std;

int N, arr[50001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    int sum=0;
    for(int i=0; i<N-1; i++){
        int w=arr[i]+arr[i+1];
        int h=abs(arr[i]-arr[i+1]);
        sum+=(w*w+h*h);
    }
    cout<<sum;
}