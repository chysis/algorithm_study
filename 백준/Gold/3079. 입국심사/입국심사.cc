#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

int N, M, T[100001];

bool solve(ll K){
    ll cnt=0;
    for(int i=0; i<N; i++){
        cnt+=K/T[i];
        if(cnt>M) break;
    }
    
    return cnt>=M;
}

int main()
{
    cin>>N>>M;
    
    ll mx=-1;
    for(int i=0; i<N; i++){
        cin>>T[i];
        mx=(mx<T[i] ? T[i] : mx);
    }
    
    ll s=0, e=mx*M+1;
    while(s+1<e){
        ll m=(s+e)/2;
        
        if(solve(m)) e=m;
        else s=m;
    }
    
    cout<<e; 
}