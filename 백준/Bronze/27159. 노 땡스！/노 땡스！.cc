#include <bits/stdc++.h>
using namespace std;

int N, arr[34], sum=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    sum=arr[0];
    for(int i=1; i<N; i++){
        if(arr[i]==arr[i-1]+1) continue;
        else sum+=arr[i];
    }
    cout<<sum;
}