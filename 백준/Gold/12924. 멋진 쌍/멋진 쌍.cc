#include <iostream>
#include <string>
#include <set>
using namespace std;

set<pair<int, string>> st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int A, B;
    cin>>A>>B;
    for(int i=A; i<B; i++){
        string cur=to_string(i);
        for(int j=1; j<cur.length(); j++){
            string s=cur.substr(j)+cur.substr(0, j);
            if(i<stoi(s) && stoi(s)<=B) st.insert({i, s});
        }
    }
    
    cout<<st.size();
}