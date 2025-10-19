#include <bits/stdc++.h>
using namespace std;

long long N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    cout<<(N-1)+2*(N-1)*(N-2)/2<<"\n";
    for(int i=2; i<=N; i++){
        cout<<1<<" "<<i<<"\n";
    }
}