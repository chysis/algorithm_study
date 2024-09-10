#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<char> v;
    stack<pair<char, int>> stk;
    string s, bomb;
    int temp=0;
    cin>>s>>bomb;
    for(int i=0; i<s.length(); i++){
        if(stk.empty() && s[i]!=bomb[0]) {
            stk.push(make_pair(s[i], 0));
            //cout<<s[i]<<" "<<0<<" 스택에 담음\n";
        }
        else if(s[i]==bomb[0]) {
            stk.push(make_pair(s[i], 1));
            //cout<<s[i]<<" "<<1<<" 스택에 담음\n";
        }
        else if(stk.top().second!=0){
            if(s[i]==bomb[stk.top().second]){
                stk.push(make_pair(s[i], stk.top().second+1));
                //cout<<s[i]<<" "<<stk.top().second<<" 스택에 담음\n";
            }
            else if(s[i]==bomb[0]){
                stk.push(make_pair(s[i], 1));
                //cout<<s[i]<<" "<<1<<" 스택에 담음\n";
            }
            else{
                stk.push(make_pair(s[i], 0));
                //cout<<s[i]<<" "<<0<<" 스택에 담음\n";
            }
        }
        else{
            stk.push(make_pair(s[i], 0));
            //cout<<s[i]<<" "<<0<<" 스택에 담음\n";
        }
        
        if(stk.top().second==bomb.length()){
            for(int j=0; j<bomb.length(); j++){
                //cout<<stk.top().first<<"지움\n";
                stk.pop();
            }
        }
    }
    if(stk.empty()) cout<<"FRULA";
    else{
        while(!stk.empty()){
            v.push_back(stk.top().first);
            stk.pop();
        }
        for(int i=0; i<v.size(); i++){
            cout<<v[v.size()-i-1];
        }
    }
}