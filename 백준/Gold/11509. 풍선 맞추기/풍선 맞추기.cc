#include <bits/stdc++.h>
using namespace std;

int N, arr[1000001], h[1000001], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    for(int i=0; i<N; i++){
        if(h[arr[i]]==0){
            ans++;
            if(arr[i]>1) h[arr[i]-1]++;
        } else{
            h[arr[i]]--;
            h[arr[i]-1]++;
        }
    }
    cout<<ans;
}