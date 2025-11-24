#include <bits/stdc++.h>
using namespace std;

long long X, K, num, l[10001], r[10001], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>X>>K;
    for(int i=0; i<X; i++){
        cin>>num;
        l[num]++;
    }
    for(int i=0; i<X; i++){
        cin>>num;
        r[num]++;
    }
    
    for(int i=1; i<=K; i++){
        ans+=(l[i]*(X-r[i]));
    }
    cout<<ans;
}