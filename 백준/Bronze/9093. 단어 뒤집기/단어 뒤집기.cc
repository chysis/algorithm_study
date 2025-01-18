#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    cin.ignore();
    
    while(T--){
        string str;
        getline(cin, str);
        
        string temp="";
        for(int i=0; i<=str.length(); i++){
            if(str[i]==' ' || str[i]=='\0'){
                reverse(temp.begin(), temp.end());
                cout<<temp;
                if(str[i]==' ') cout<<str[i];
                temp="";
            } else{
                temp+=str[i];
            }
        }
        cout<<"\n";
    }
}