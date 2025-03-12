#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>str;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='(') s.push(str[i]);
        else if(str[i]==')'){
            if(!s.empty() && s.top()=='(') s.pop();
            else s.push(str[i]);
        }
    }
    
    cout<<s.size();
}