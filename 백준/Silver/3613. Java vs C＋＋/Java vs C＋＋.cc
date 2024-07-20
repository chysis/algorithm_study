#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin>>str;
    
    bool hasUpper=false;
    bool hasUnderline=false;
    
    for(int i=0; i<str.length(); i++){
        if(i==0 && ((str[i]>='A' && str[i]<='Z') || str[i]=='_')){
            cout<<"Error!";
            return 0;
        }
        
        if(i==str.length()-1 && str[i]=='_'){
            cout<<"Error!";
            return 0;
        } 
        
        if(str[i]=='_' && str[i+1]=='_'){
            cout<<"Error!";
            return 0;
        }
        
        if(str[i]!='_' && !(str[i]>='A' && str[i]<='Z') && !(str[i]>='a' && str[i]<='z')){
            cout<<"Error!";
            return 0;
        }
        
         if(str[i]=='_') hasUnderline=true;
        else if(str[i]>='A' && str[i]<='Z') hasUpper=true;
    }
    
    if((hasUpper && hasUnderline)){
        cout<<"Error!";
        return 0;
    }
    
    if(hasUpper){
        string newStr="";
        
        int idx=0;
        while(true){
            if(idx>=str.length()) break;
            
            if(str[idx]>='A' && str[idx]<='Z'){
                newStr+='_';
                newStr+=str[idx]+32;
                idx++;
            } else{
                newStr+=str[idx];
                idx++;
            }
        }
        
        cout<<newStr;
    } else{
        string newStr="";
        
        int idx=0;
        while(true){
            if(idx>=str.length()) break;
            
            if(str[idx]=='_'){
                idx++;
                newStr+=str[idx]-32;
                idx++;
            } else{
                newStr+=str[idx];
                idx++;
            }
        }
        
        cout<<newStr;
    }
}