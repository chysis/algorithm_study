#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H1, M1, H2, M2;
    char C;
    cin>>H1>>C>>M1;
    cin>>H2>>C>>M2;
    if(H1*60+M1>H2*60+M2) cout<<"NO";
    else cout<<"YES";
}