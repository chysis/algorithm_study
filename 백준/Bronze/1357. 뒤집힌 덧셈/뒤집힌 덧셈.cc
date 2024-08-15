#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string X, Y;
    cin>>X>>Y;
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    string str=to_string(stoi(X)+stoi(Y));
    reverse(str.begin(), str.end());
    
    int idx=0;
    while(true){
        if(str[idx]=='0') idx++;
        else break;
    }
    
    for(int i=idx; i<str.length(); i++){
        cout<<str[i];
    }
}