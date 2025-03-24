#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K, arr[10001], maxInput=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        maxInput=max(maxInput, arr[i]);
    }

    ll s=1, e=maxInput, ans=0;
    while(s<=e){
        ll m=(s+e)/2;
        ll temp=0;
        for(int i=0; i<N; i++){
            temp+=(arr[i]/m);
        }
        
        if(temp>=K) {
            ans=max(ans, m);
            s=m+1;
        }
        else e=m-1;
    }
    
    cout<<ans;
}