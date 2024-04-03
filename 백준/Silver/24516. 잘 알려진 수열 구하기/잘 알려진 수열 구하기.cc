#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        cout<<2+(i-1)*2<<" ";
    }
}