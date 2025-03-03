#include <bits/stdc++.h>
using namespace std;

int N;
map<string, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        string str, ext;
        cin>>str;
        for(int j=0; j<str.length(); j++){
            if(str[j]=='.'){
                ext=str.substr(j+1);
            }
        }
        
        if(m.find(ext)==m.end()) m[ext]=1;
        else m[ext]++;
    }
    
    for(auto it: m){
        cout<<(it.first)<<" "<<(it.second)<<"\n";
    }
}