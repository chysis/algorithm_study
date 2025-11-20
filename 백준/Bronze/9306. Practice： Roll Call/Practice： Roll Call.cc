#include <bits/stdc++.h>
using namespace std;

int N;
string A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>A>>B;
        cout<<"Case "<<i<<": "<<B<<", "<<A<<"\n"; 
    }
}