#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, h[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>h[i];
    
    ll ans=0;
    for(int i=0; i<N; i++) ans+=h[i];
    
    if(ans%3!=0) return cout<<"NO", 0;
    
    ll e=0, o=0;
    for(int i=0; i<N; i++){
        e+=h[i]/2;
        if(h[i]%2==1) o++;
    }
    
    if(e>=o) cout<<"YES";
    else cout<<"NO";
}