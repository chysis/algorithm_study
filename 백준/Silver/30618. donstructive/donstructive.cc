#include <bits/stdc++.h>
using namespace std;

int N, arr[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N/2; i++){
        arr[i]=2*i-1;
        arr[N-i+1]=2*i;
    }
    if(N%2==1) arr[N/2+1]=N;
    
    for(int i=1; i<=N; i++) cout<<arr[i]<<" ";
}