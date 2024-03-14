#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, ans=0;
    cin>>N;
    while(N--){
        string str;
        cin>>str;
        if(str=="ENTER"){
            ans+=s.size();
            s.clear();
        }
        else s.insert(str);
    }
    ans+=s.size();
    cout<<ans;
}