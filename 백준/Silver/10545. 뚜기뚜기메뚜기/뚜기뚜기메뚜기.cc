#include <bits/stdc++.h>
using namespace std;

int num, arr[10];
string S, ans="";

string keyMap(char c, char prev){
    string res="";
    
    if(c<='c'){
        if(prev<='c') res+='#';
        for(int i=0; i<c-'a'+1; i++) res+=to_string(arr[2]);
    }
    else if(c<='f'){
        if(prev>='d' && prev<='f') res+='#';
        for(int i=0; i<c-'d'+1; i++) res+=to_string(arr[3]);
    }
    else if(c<='i'){
        if(prev>='g' && prev<='i') res+='#';
        for(int i=0; i<c-'g'+1; i++) res+=to_string(arr[4]);
    }
    else if(c<='l'){
        if(prev>='j' && prev<='l') res+='#';
        for(int i=0; i<c-'j'+1; i++) res+=to_string(arr[5]);
    }
    else if(c<='o'){
        if(prev>='m' && prev<='o') res+='#';
        for(int i=0; i<c-'m'+1; i++) res+=to_string(arr[6]);
    }
    else if(c<='s'){
        if(prev>='p' && prev<='s') res+='#';
        for(int i=0; i<c-'p'+1; i++) res+=to_string(arr[7]);
    }
    else if(c<='v'){
        if(prev>='t' && prev<='v') res+='#';
        for(int i=0; i<c-'t'+1; i++) res+=to_string(arr[8]);
    }
    else if(c<='z'){
        if(prev>='w' && prev<='z') res+='#';
        for(int i=0; i<c-'w'+1; i++) res+=to_string(arr[9]);
    }
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=1; i<=9; i++){
        cin>>num;
        arr[num]=i;
    }
    cin>>S;
    
    for(int i=0; i<S.length(); i++){
        ans+=keyMap(S[i], i==0 ? 'z'+1 : S[i-1]);
    }
    cout<<ans;
}