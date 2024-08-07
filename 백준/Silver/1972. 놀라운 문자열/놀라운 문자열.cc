#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> v;
set<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        string str;
        cin>>str;
        
        if(str=="*") break;
        
        bool flag=true;
        
        for(int i=0; i<str.length()-1; i++){
            for(int j=0; j<str.length()-i-1; j++){
                string temp="";
                temp+=str[j];
                temp+=str[j+i+1];
                
                s.insert(temp);
                v.push_back(temp);
            }
            
            if(s.size()!=v.size()){
                flag=false;
                s.clear();
                v.clear();
                break;
            }
            
            s.clear();
            v.clear();
        }
        
        if(flag) cout<<str<<" is surprising.\n";
        else cout<<str<<" is NOT surprising.\n";
    }
}