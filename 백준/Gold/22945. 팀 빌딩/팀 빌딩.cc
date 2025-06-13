#include <bits/stdc++.h>
using namespace std;

int N, arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    int s=0, e=N-1, ans=0;
    while(s<e){
        int c=(e-s-1)*min(arr[s], arr[e]);
        if(c>ans){
            ans=c;
            if(arr[s]<arr[e]) s++;
            else e--;
        }else{
            if(arr[s]<arr[e]) s++;
            else e--;
        }
    }
    cout<<ans;
}