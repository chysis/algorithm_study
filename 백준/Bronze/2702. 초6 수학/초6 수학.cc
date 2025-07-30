#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int gcd(int a, int b){
    return (a%b) ? gcd(b, a%b) : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>A>>B;
        cout<<A*B/gcd(A, B)<<" "<<gcd(A, B)<<"\n";
    }
}