#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    getline(cin, str);
    
    int idx=0;
    
    string temp="";
    while(idx<=str.length()){
        if(str[idx]=='<'){
            for(int i=temp.length()-1; i>=0; i--){
                cout<<temp[i];
            }
            temp="";

            while(true){
                cout<<str[idx];
                idx++;
                if(str[idx-1]=='>') break;
            }
        } else if(str[idx]==' ' || str[idx]=='\0'){
            for(int i=temp.length()-1; i>=0; i--){
                cout<<temp[i];
            }
            if(str[idx]==' ') cout<<str[idx];
            temp="";
            idx++;
        } else{
            temp+=str[idx];
            idx++;
        }
    }
}