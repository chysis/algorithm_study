#include <bits/stdc++.h>
using namespace std;

long long ans=0;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    for(int i=0; i<S.length(); i++){
        ans+=pow(26, S.length()-1-i)*(S[i]-'A'+1);
    }
    cout<<ans;
}