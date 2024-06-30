#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        s.insert(str);
    }
    
    int ans=0;
    for(int i=0; i<M; i++){
        string str;
        cin>>str;
        if(s.find(str)!=s.end()){
            ans++;
        }
    }
    
    cout<<ans;
}