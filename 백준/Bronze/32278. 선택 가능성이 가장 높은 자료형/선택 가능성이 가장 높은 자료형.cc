#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long num;
    cin>>num;
    if(num>=SHRT_MIN && num<=SHRT_MAX) cout<<"short";
    else if(num>=INT_MIN && num<=INT_MAX) cout<<"int";
    else cout<<"long long";
}