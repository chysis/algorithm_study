#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s1, s2;
    cin>>s1>>s2;
    
    string t1="", t2="";
    while(t1.length()<100){
        t1.append(s1);
    }
    
    while(t2.length()<100){
        t2.append(s2);
    }
    
    for(int i=0; i<100; i++){
        if(t1[i]!=t2[i]){
            cout<<0;
            return 0;
        }
    }
    
    cout<<1;
}