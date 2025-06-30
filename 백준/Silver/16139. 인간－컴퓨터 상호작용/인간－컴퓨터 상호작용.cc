#include <bits/stdc++.h>
using namespace std;

string S;
int q, l, r, arr[200001][27];
char a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S>>q;
    for(int i=0; i<S.length(); i++) arr[i][S[i]-'a']++;
    for(int i=1; i<S.length(); i++){
        for(int j=0; j<26; j++){
            arr[i][j]+=arr[i-1][j];
        }
    }
    
    for(int i=0; i<q; i++){
        cin>>a>>l>>r;
        if(l==0) cout<<arr[r][a-'a']<<"\n";
        else cout<<arr[r][a-'a']-arr[l-1][a-'a']<<"\n";
    }
}