#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

stack<char> s;
vector<char> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int cnt=1;
    string str;
    while(true){
        cin>>str;
        if(str[0]=='-') break;
        
        int ans=0;
        for(int i=0; i<str.length(); i++){
            if(str[i]=='{'){
                s.push(str[i]);
            } else if(str[i]=='}'){
                if(!s.empty()){
                    s.pop();
                } else{
                    ans++;
                    s.push('{');
                }
            }
        }
        
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        
        while(!v.empty()){
            ans++;
            v.pop_back();
            v.pop_back();
        }
        
        cout<<cnt<<". "<<ans<<"\n";
        cnt++;
        s={};
        v.clear();
    }
}