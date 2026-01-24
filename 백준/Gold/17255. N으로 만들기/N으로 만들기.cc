#include <bits/stdc++.h>
using namespace std;

string N;
unordered_map<string, int> um;

int solve(string s){
    if(s.length()==1) return 1;
    if(um.find(s)!=um.end()) return um[s];
    
    string a=s.substr(0, s.length()-1);
    string b=s.substr(1);
    
    int& temp=um[s];
    if(a==b) temp+=solve(a);
    else{
        temp+=solve(a);
        temp+=solve(b);
    }
    
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    cout<<solve(N);
}