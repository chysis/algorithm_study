#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int A, B, C;
    cin>>A>>B>>C;
    cout<<A+B-C<<"\n"<<stoi(to_string(A)+to_string(B))-C;
}