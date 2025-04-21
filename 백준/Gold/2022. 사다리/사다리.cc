#include <bits/stdc++.h>
#define ld long double
using namespace std;

ld X, Y, C, d=0.0001;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout<<fixed;
    cout.precision(4);
    
    cin>>X>>Y>>C;
    ld s=0, e=X>Y ? Y : X, m;
    while(s+d<e){
        m=(s+e)/2;
        ld temp=(sqrt(pow(X, 2)-pow(m, 2))*sqrt(pow(Y, 2)-pow(m, 2)))/(sqrt(pow(X, 2)-pow(m, 2))+sqrt(pow(Y, 2)-pow(m, 2)));
        
        if(temp<C) e=m;
        else s=m;
    }
    
    cout<<e;
}