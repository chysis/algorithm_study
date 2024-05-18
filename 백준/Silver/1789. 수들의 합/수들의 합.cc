#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll N;
    cin>>N;
    
    for(ll i=1; ;i++){
        if(i*(i+1)>2*N){
            cout<<i-1;
            break;
        }
    }
}