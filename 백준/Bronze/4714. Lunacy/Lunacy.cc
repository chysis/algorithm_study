#include <bits/stdc++.h>
using namespace std;

double X;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout<<fixed;
    cout.precision(2);
    
    while(true){
        cin>>X;
        if(X<0) break;
        
        cout<<"Objects weighing "<<X<<" on Earth will weigh "<<X*0.167<<" on the moon.\n";
    }
}