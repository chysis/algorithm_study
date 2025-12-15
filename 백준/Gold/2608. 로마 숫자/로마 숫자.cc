#include <bits/stdc++.h>
using namespace std;

string A, B;

int romanToInt(string S){
    int res=0, idx=0;
    while(idx<S.length()){
        if(S[idx]=='I'){
            if(idx+1<S.length() && S[idx+1]=='V'){
                res+=4; idx+=2;
            }
            else if(idx+1<S.length() && S[idx+1]=='X'){
                res+=9; idx+=2;
            }
            else{
                res+=1; idx++;
            }
        }
        else if(S[idx]=='X'){
            if(idx+1<S.length() && S[idx+1]=='L'){
                res+=40; idx+=2;
            }
            else if(idx+1<S.length() && S[idx+1]=='C'){
                res+=90; idx+=2;
            }
            else{
                res+=10; idx++;
            }
        }
        else if(S[idx]=='C'){
            if(idx+1<S.length() && S[idx+1]=='D'){
                res+=400; idx+=2;
            }
            else if(idx+1<S.length() && S[idx+1]=='M'){
                res+=900; idx+=2;
            }
            else{
                res+=100; idx++;
            }
        }
        else if(S[idx]=='V'){
            res+=5; idx++;
        }
        else if(S[idx]=='L'){
            res+=50; idx++;
        }
        else if(S[idx]=='D'){
            res+=500; idx++;
        }
        else if(S[idx]=='M'){
            res+=1000; idx++;
        }
    }
    return res;
}

string intToRoman(string N){
    string res="";
    for(int i=0; i<N.length(); i++){
        int cur=(N[i]-'0')*pow(10, N.length()-i-1);
        
        if(cur>=1000){
            for(int j=0; j<cur/1000; j++) res+="M";
        }
        else if(cur==900) res+="CM";
        else if(cur>=500){
            res+="D";
            for(int j=0; j<(cur-500)/100; j++) res+="C";
        }
        else if(cur==400) res+="CD";
        else if(cur>=100){
            for(int j=0; j<cur/100; j++) res+="C";
        }
        else if(cur==90) res+="XC";
        else if(cur>=50){
            res+="L";
            for(int j=0; j<(cur-50)/10; j++) res+="X";
        }
        else if(cur==40) res+="XL";
        else if(cur>=10){
            for(int j=0; j<cur/10; j++) res+="X";
        }
        else if(cur==9) res+="IX";
        else if(cur>=5){
            res+="V";
            for(int j=0; j<(cur-5); j++) res+="I";
        }
        else if(cur==4) res+="IV";
        else{
            for(int j=0; j<cur; j++) res+="I";
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>A>>B;
    int ans=romanToInt(A)+romanToInt(B);
    cout<<ans<<"\n"<<intToRoman(to_string(ans));
}