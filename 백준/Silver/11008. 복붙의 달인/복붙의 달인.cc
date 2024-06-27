#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        string s, p;
        cin>>s>>p;
        
        int idx=0, cnt=0;
        while(true){
            if(idx>=s.length()) break;
            
            if(s.substr(idx, p.length())==p){
                cnt++;
                idx+=p.length();
            } else{
                cnt++;
                idx++;
            }
        }
        
        cout<<cnt<<"\n";
    }
}