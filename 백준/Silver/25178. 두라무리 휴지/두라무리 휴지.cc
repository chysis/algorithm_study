#include <iostream>
#include <string>
using namespace std;

int N;
int a1[26], a2[26];
string str1, str2;

bool allSame(string str1, string str2){
    for(int i=0; i<26; i++){
        if(a1[i]!=a2[i]) return false;
    }
    return true;
}

string cutVowel(string str){
    string temp="";
    for(int i=0; i<str.length(); i++){
        if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u'){
            temp+=str[i];
        }
    }
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>str1>>str2;
    for(int i=0; i<N; i++){
        a1[str1[i]-'a']++;
        a2[str2[i]-'a']++;
    }
    
    if(!allSame(str1, str2)) cout<<"NO";
    else{
        if(str1[0]!=str2[0] || str1[N-1]!=str2[N-1]) cout<<"NO";
        else{
            if(cutVowel(str1)!=cutVowel(str2)) cout<<"NO";
            else cout<<"YES";
        }
    }
}