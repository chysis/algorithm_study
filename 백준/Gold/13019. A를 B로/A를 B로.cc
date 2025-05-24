#include <bits/stdc++.h>
using namespace std;

int s1[27], s2[27], ans=0;
string A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>A>>B;
    if(A.length()!=B.length()) return cout<<-1, 0;
    
    for(int i=0; i<A.length(); i++) s1[A[i]-'A']++;
    for(int i=0; i<B.length(); i++) s2[B[i]-'A']++;
    
    for(int i=0; i<26; i++){
        if(s1[i]!=s2[i]) return cout<<-1, 0;
    }
    
    int idx=B.length()-1;
    for(int i=A.length()-1; i>=0; i--){
        if(A[i]!=B[idx]) ans++;
        else idx--;
    }
    cout<<ans;
}