#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string target;
    cin>>target;
    
    int N, ans=0;
    cin>>N;
    
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        if(target.substr(0, 5)==str.substr(0, 5)) ans++;
    }
    
    cout<<ans;
}