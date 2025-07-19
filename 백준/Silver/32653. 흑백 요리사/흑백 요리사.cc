#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

ll N, arr[200001];

ll gcd(ll a, ll b){
    return (a % b) ? gcd(b, a % b) : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    ll cur=arr[0];
    for(int i=1; i<N; i++){
        ll temp=gcd(cur, arr[i]);
        cur=cur*arr[i]/temp;
    }
    
    bool flag=false;
    for(int i=0; i<N; i++){
        if((cur/arr[i])%2!=0){
            flag=true;
            break;
        }
    }
    
    if(flag) cout<<cur*2;
    else cout<<cur;
}