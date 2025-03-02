#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin>>str;
    if(str.length()==1){
        cout<<0<<"\n"<<((str[0]-'0')%3==0 ? "YES" : "NO");
        return 0;
    }
    
    int cnt=0;
    while(true){
        int num=0;
        for(int i=0; i<str.length(); i++){
            num+=(str[i]-'0');
        }
        cnt++;
        str=to_string(num);
        
        if(num<10){
            cout<<cnt<<"\n"<<(num%3==0 ? "YES" : "NO");
            break;
        }
    }
}