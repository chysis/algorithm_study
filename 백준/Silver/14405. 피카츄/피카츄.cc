#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin>>str;
    
    int idx=0;
    while(idx<str.length()){
        if(str.substr(idx, 2)=="pi"){
            idx+=2;
        } else if(str.substr(idx, 2)=="ka"){
            idx+=2;
        } else if(str.substr(idx, 3)=="chu"){
            idx+=3;
        } else{
            break;
        }
    }
    
    if(idx<str.length()) cout<<"NO";
    else cout<<"YES";
}