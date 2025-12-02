#include <bits/stdc++.h>
using namespace std;

int X, w=0, m=0;
string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>X>>S;
    while(true){
        if(S.length()==0) break;

        if(S[0]=='M'){
            if(abs(m+1-w)>X){
                if(S.length()==1) break;
                if(S[1]=='M') break;
                else{
                    w++;
                    S.erase(1, 1);
                }
            }else{
                m++;
                S.erase(0, 1);
            }
        }else if(S[0]=='W'){
            if(abs(w+1-m)>X){
                if(S.length()==1) break;
                if(S[1]=='W') break;
                else{
                    m++;
                    S.erase(1, 1);
                }
            }else{
                w++;
                S.erase(0, 1);
            }
        }
    }
    
    cout<<w+m;
}