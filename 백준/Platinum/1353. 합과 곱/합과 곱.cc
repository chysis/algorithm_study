#include <bits/stdc++.h>
using namespace std;

long double S, P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S>>P;
    if(pow(M_E, S/M_E)<P){
        cout<<-1;
        return 0;
    }
    
    if(S==P){
        cout<<1;
        return 0;
    }
    
    for(int i=2; i<=ceil(S/M_E)+1; i++){
        if(pow(S/i, i)>=P){
            cout<<i;
            return 0;
        }
    }
    
    cout<<-1;
}