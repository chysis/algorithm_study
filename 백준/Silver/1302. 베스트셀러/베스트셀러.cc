#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        
        if(m.find(str)==m.end()){
            m.insert({str, 1});
        } else{
            m[str]++;
        }
    }
    
    int maxValue=-1;
    string ans;
    for(auto a: m){
        if(maxValue<a.second){
            maxValue=a.second;
            ans=a.first;
        }
    }
    
    cout<<ans;
}