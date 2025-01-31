#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int letter[27];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin>>str;
    
    for(int i=0; i<str.length(); i++){
        letter[str[i]-'A']++;
    }
    
    int oddCnt=0;
    for(int i=0; i<26; i++){
        if(letter[i]%2==1) oddCnt++;
    }
    
    if((str.length()%2==0 && oddCnt>0) || (str.length()%2==1 && oddCnt>1)){
        cout<<"I'm Sorry Hansoo";
        return 0;
    }
    
    string prefix="", mid="";
    
    for(int i=0; i<26; i++){
        if(letter[i]>0){
            for(int j=0; j<letter[i]/2; j++) prefix+=('A'+i);
            if(letter[i]%2==1){
                for(int j=0; j<letter[i]-(letter[i]/2)*2; j++) mid+=('A'+i);
            }
        }
    }
    
    cout<<prefix<<mid;
    reverse(prefix.begin(), prefix.end());
    cout<<prefix;
}