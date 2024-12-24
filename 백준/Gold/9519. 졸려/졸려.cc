#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;    

vector<string> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int X;
    cin>>X;
    
    string str;
    cin>>str;
    v.push_back(str);
    
    string temp;
    while(true){
        string even="", odd="";
        for(int i=0; i<str.length(); i+=2) even+=v.back()[i];
        for(int i=1; i<str.length(); i+=2) odd+=v.back()[i];
        reverse(odd.begin(), odd.end());
        temp=even+odd;
        v.push_back(temp);
        
        if(temp==str) break;
    }
    
    cout<<v[X%(v.size()-1)];
}