#include <bits/stdc++.h>
using namespace std;

int A, T, G;

string getOrd(int repeat){
    string res="0101";
    for(int i=0; i<repeat; i++) res+='0';
    for(int i=0; i<repeat; i++) res+='1';
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>A>>T>>G;
    int cur=0, pos=0, cnt[2]={0, 0}, repeat=2; // 0: 뻔, 1: 데기
    string ord=getOrd(repeat);
    
    while(true){
        if(pos>=ord.length()){
            pos=0;
            repeat++;
            ord=getOrd(repeat);
        }
        
        cnt[ord[pos]-'0']++;
        pos++;
        
        if(cnt[G]>=T){
            cout<<cur;
            break;
        }
        
        cur++;
        if(cur>=A) cur=0;
    }
}