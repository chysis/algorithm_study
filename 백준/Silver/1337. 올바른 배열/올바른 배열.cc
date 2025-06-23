#include <bits/stdc++.h>
using namespace std;

int N, arr[51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    sort(arr, arr+N);
    
    int ans=4;
    for(int i=0; i<N; i++){
        int s=i, e=N-1;
        while(s<e){
            if(arr[e]-arr[s]>4) e--;
            else{
                ans=min(ans, 5-(e-s+1));
                break;
            }
        }
    }
    
    cout<<ans;
}