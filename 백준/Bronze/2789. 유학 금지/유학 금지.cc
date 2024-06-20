#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin>>str;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='C'||str[i]=='A'||str[i]=='M'||str[i]=='B'||str[i]=='R'||str[i]=='I'||str[i]=='D'||str[i]=='G'||str[i]=='E') continue;
        cout<<str[i];
    }
}