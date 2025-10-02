#include <bits/stdc++.h>
using namespace std;

int X, Y;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>X>>Y;
    int diff=Y-X;
    if(diff==0) return cout<<0, 0;
    
    int k=sqrt(diff);
    if(k*k==diff) cout<<2*k-1;
    else if(diff<=k*(k+1)) cout<<2*k;
    else cout<<2*k+1;
}