#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    int ans=0;
    cin>>S;
    for(int i=0; i<S.length(); i++){
        if(S[i]==',') ans++;
    }
    cout<<ans+1;
}