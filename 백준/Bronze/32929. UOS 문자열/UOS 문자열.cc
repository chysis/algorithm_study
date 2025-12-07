#include <iostream>
using namespace std;

int main()
{
    int n;
    char a[4]={'U', 'O', 'S'};
    cin>>n;
    cout<<a[(n%3==0 ? 2 : n%3-1)];
}