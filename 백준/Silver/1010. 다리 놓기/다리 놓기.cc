#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll comb(ll n, ll m){
    vector<ll> v;
    ll a=1;
    if(n>m/2)n=m-n;
    for(int i=0; i<n; i++){
        a*=(m-i);
        if(a%(n-i)==0) a/=(n-i);
        else v.push_back(n-i);
    }
    for(auto i:v) a/=i;
    return a;
}

int main()
{
    ll T, N, M;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N>>M;
        cout<<comb(N, M)<<"\n";
    }
}