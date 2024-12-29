#include <iostream>
#include <string>
using namespace std;

string str;
char ans[111];

void solve(int s, int e){
    int mnIdx=999;
    char mnChar='a';
    for(int i=s; i<=e; i++){
        if(str[i]<mnChar){
            mnChar=str[i];
            mnIdx=i;
        }
    }
    
    ans[mnIdx]=mnChar;
    for(int i=0; i<str.length(); i++){
        if(ans[i]!='.') cout<<ans[i];
    }
    cout<<"\n";
    
    if(mnIdx+1<=e) solve(mnIdx+1, e);
    if(mnIdx-1>=s) solve(s, mnIdx-1);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>str;
    for(int i=0; i<str.length(); i++){
        ans[i]='.';
    }
    solve(0, str.length()-1);
}