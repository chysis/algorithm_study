#include <bits/stdc++.h>
using namespace std;

int N, ans=0;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>S;
    for(int i=0; i<S.length()-1; i++){
        if(S[i]=='W' && S[i+1]=='E') ans++;
    }
    cout<<ans+1;
}