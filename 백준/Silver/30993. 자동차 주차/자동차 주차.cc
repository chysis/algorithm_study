#include <iostream>

#define ll long long
using namespace std;

ll fac(int N){
    if(N==1) return 1;
    else return N*fac(N-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, A, B, C;
    cin>>N>>A>>B>>C;
    cout<<fac(N)/fac(A)/fac(B)/fac(C);
}