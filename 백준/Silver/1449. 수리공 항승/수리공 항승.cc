#include <iostream>
#include <algorithm>
using namespace std;

int N, L, arr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>L;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N);
    
    int idx=0, ans=0;
    while(idx<N){
        int temp=idx;
        while(true){
            temp++;
            if(temp>=N) break;
            if(arr[temp]-arr[idx]>L-1){
                ans++;
                break;
            }
        }
        
        if(idx!=temp && temp==N) ans++;
        idx=temp;
    }
    
    cout<<ans;
}