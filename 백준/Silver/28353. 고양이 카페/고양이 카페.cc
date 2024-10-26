#include <iostream>
#include <algorithm>
using namespace std;

int arr[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N);
    int s=0, e=N-1, ans=0;
    while(s<e){
        if(arr[s]+arr[e]<=K){
            ans++;
            s++; e--;
        } else{
            e--;
        }
    }
    
    cout<<ans;
}