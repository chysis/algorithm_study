#include <bits/stdc++.h>
using namespace std;

int N, T;
string X, ans="0";

string max(string a, string b){
    if(a+b > b+a) return a;
    else return b;
}

void solve(int dep, string s){
    if(dep==T){
        ans=max(ans, s);
        return;
    }
    
    solve(dep+1, s.substr(0, s.length()/2));
    solve(dep+1, s.substr(s.length()/2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>T>>X;
    solve(0, X);
    cout<<ans;
}