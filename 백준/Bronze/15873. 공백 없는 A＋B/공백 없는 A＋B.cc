#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    cin>>S;
    if(S.length()==2) cout<<stoi(S.substr(0, 1))+stoi(S.substr(1, 1));
    else if(S.length()==3){
        if(S[1]=='0') cout<<stoi(S.substr(0, 2))+stoi(S.substr(2, 1));
        else cout<<stoi(S.substr(0, 1))+stoi(S.substr(1, 2));
    }
    else if(S.length()==4){
        cout<<stoi(S.substr(0, 2))+stoi(S.substr(2, 2));
    }
}