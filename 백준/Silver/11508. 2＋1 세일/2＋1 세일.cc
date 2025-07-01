#include <bits/stdc++.h>
using namespace std;

int N, arr[100001], total=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i], total+=arr[i];
    sort(arr, arr+N, greater<int>());
    
    for(int i=2; i<N; i+=3){
        total-=arr[i];
    }
    cout<<total;
}