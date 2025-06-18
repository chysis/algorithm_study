#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    if(N==0) cout<<1;
    else if(N==1) cout<<1;
    else if(N==2) cout<<2;
    else if(N==3) cout<<6;
    else if(N==4) cout<<4;
    else cout<<0;
}