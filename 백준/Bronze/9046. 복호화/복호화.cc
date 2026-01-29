#include <bits/stdc++.h>
using namespace std;

int T, arr[26];
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    cin.ignore();
    while(T--){
        for(int i=0; i<26; i++) arr[i]=0;
        getline(cin, S);
        for(int i=0; i<S.length(); i++){
            if(S[i]==' ') continue;
            arr[S[i]-'a']++;
        }
        
        int most=-1;
        char c;
        for(int i=0; i<26; i++){
            if(arr[i]>most){
                most=arr[i];
                c=i+'a';
            } else if(arr[i]==most){
                c='?';
            }
        }
        
        cout<<c<<"\n";
    }
}
