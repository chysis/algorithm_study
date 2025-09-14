#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, A, B, W, H;
pair<ll, ll> arr[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    W=arr[0].first, H=arr[0].second;
    for(int i=1; i<N; i++){
        ll asc=max(W, arr[i].first)*max(H, arr[i].second);
        ll desc=max(W, arr[i].second)*max(H, arr[i].first);
        if(asc<desc){
            W=max(W, arr[i].first);
            H=max(H, arr[i].second);
        }else{
            W=max(W, arr[i].second);
            H=max(H, arr[i].first);
        }
    }
    cout<<W*H;
}