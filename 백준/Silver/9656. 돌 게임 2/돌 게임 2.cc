#include <iostream>
using namespace std;

int arr[51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    if(N%2==0) cout<<"SK";
    else cout<<"CY";
}