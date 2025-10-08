#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, arr[200001], ans=0, m=INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    for(int i=0; i<N; i++){
        if(m<arr[i]){
            ans=max(ans, arr[i]-m);
        } else m=min(m, arr[i]);
    }
    cout<<ans;
}