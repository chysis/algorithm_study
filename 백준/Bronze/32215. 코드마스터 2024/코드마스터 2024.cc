#include <iostream>
using namespace std;

int N, M, K;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K;
    cout<<(K+1)*M;
}