#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double b, c, a1, a2;
    cin>>b>>c>>a1>>a2;
    
    cout<<fixed;
    cout.precision(10);
    
    cout<<(b+sqrt(pow(b, 2)+4*c))/2;
}