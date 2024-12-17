#include <iostream>
#include <string>
using namespace std;

bool solve(string& str, int s, int e){
    while(s<e){
        if(str[s++]!=str[e--]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        
        int s=0, e=str.length()-1, ans=0;
        
        while(s<e){
            if(str[s]==str[e]){
                s++, e--;
            } else{
                if(solve(str, s+1, e) || solve(str, s, e-1)) ans=1;
                else ans=2;
                break;
            }
        }
        
        cout<<ans<<"\n";
    }
}