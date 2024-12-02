#include <iostream>
#include <algorithm>
using namespace std;

int arr[300001], diff[300001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<N-1; i++){
        diff[i]=arr[i+1]-arr[i];
    }
    
    sort(diff, diff+N-1);
    
    int ans=arr[N-1]-arr[0];
    for(int i=0; i<K-1; i++){
        ans-=diff[N-2-i];
    }
    
    cout<<ans;
}