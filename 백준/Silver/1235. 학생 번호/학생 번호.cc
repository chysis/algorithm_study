#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> v;
set<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    
    int len=v[0].length();
    
    for(int i=1; i<=len; i++){
        s.clear();
        for(int j=0; j<N; j++){
            string temp=v[j].substr(len-i);
            if(s.find(temp)==s.end()){
                s.insert(temp);
            }
        }

        if(s.size()==N){
            cout<<i;
            break;
        }
    }
}