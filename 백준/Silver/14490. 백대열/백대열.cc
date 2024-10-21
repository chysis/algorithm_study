#include <iostream>
using namespace std;

int gcd(int a, int b){
    return (b==0) ? a : gcd(b, a%b); 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    char c;
    cin>>N>>c>>M;
    
    int g=gcd(N, M);
    cout<<N/g<<c<<M/g;
}