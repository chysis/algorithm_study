#include <bits/stdc++.h>
using namespace std;

int T;
double N;
string X;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout<<fixed;
    cout.precision(4);
    
    cin>>T;
    while(T--){
        cin>>N>>X;
        if(X=="kg") cout<<N*2.2046<<" lb\n";
        else if(X=="lb") cout<<N*0.4536<<" kg\n";
        else if(X=="l") cout<<N*0.2642<<" g\n";
        else if(X=="g") cout<<N*3.7854<<" l\n";
    }
}