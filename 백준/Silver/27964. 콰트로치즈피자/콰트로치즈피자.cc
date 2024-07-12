#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        if(str.length()<6) continue;
        if(str.substr(str.length()-6, 6)=="Cheese"){
            s.insert(str);
        }
    }
    
    if(s.size()>=4) cout<<"yummy";
    else cout<<"sad";
}