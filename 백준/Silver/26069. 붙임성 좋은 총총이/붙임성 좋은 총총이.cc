#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    s.insert("ChongChong");
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string A, B;
        cin>>A>>B;
        if(s.find(A)!=s.end()) s.insert(B);
        else if(s.find(B)!=s.end()) s.insert(A);
    }
    
    cout<<s.size();
}