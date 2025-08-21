#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    string S="WelcomeToSMUPC";
    cin>>N, N--;
    cout<<S[N%14];
}