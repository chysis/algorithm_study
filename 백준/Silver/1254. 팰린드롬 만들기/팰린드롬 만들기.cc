#include <bits/stdc++.h>
using namespace std;

string S;

bool isPalindrome(string S){
    if(S.length()==1) return true;
    
    int s=0, e=S.length()-1;
    while(s<e){
        if(S[s]!=S[e]) return false;
        s++, e--;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    for(int i=0; i<S.length(); i++){
        if(isPalindrome(S.substr(i))){
            cout<<S.length()+i;
            break;
        }
    }
}