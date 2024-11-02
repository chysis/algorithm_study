#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cout<<fixed;
    cout.precision(10);
    
    double A, B;
    cin>>A>>B;
    cout<<1/(1+pow(10, (B-A)/400));
}