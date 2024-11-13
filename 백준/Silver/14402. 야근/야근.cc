#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int Q, ans=0;
    cin>>Q;
    while(Q--){
        string str;
        char c;
        cin>>str>>c;
        if(um.find(str)!=um.end()){
            if(c=='+') um[str]++;
            else{
                if(um[str]<=0) ans++;
                else{
                    um[str]--;
                }
            }
        } else{
            if(c=='+') um[str]=1;
            else{
                ans++;
                um[str]=0;
            }
        }
    }
    
    for(auto a: um){
        if(a.second>0) ans+=a.second;
    }
    
    cout<<ans;
}