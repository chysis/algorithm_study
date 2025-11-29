#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int D, E, num;
    char c;
    cin>>D>>E;
    while(E--){
        cin>>c>>num;
        if(c=='+') D+=num;
        else D-=num;
    }
    cout<<D;
}