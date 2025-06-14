#include <bits/stdc++.h>
using namespace std;

int idx=-1;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    for(int i=0; i<S.length(); i++){
        if(S[i]=='x'){
            idx=i;
            break;
        }
    }
    
    if(idx==-1){
        cout<<0;
        return 0;
    }
    
    string ans=S.substr(0, idx);
    if(ans=="") cout<<1;
    else if(ans=="-") cout<<-1;
    else cout<<ans;
}