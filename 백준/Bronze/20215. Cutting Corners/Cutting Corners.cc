#include <bits/stdc++.h>
using namespace std;

double W, H;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>W>>H;
    cout<<fixed;
    cout.precision(6);
    cout<<fabs((W+H)-(sqrt(W*W+H*H)));
}