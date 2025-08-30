#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, K, arr[1001], ans=INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    for(int i=0; i<N; i++){
        int temp=N;
        for(int j=0; j<N; j++){
            int expect=arr[i]+(j-i)*K;
            if(expect<1) break;
            if(arr[j]==arr[i]+(j-i)*K) temp--;
        }
        ans=min(ans, temp);
    }
    cout<<ans;
}