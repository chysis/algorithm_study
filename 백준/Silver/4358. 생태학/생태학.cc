#include <bits/stdc++.h>
using namespace std;

map<string, double> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cnt=0;
    string str;
    while(getline(cin, str)){
        cnt++;
        if(m.find(str)==m.end()){
            m[str]=1;
        } else m[str]++;
    }
    
    cout<<fixed;
    cout.precision(4);
    
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<" ";
        cout<<(it->second)*100/cnt<<"\n";
    }
}