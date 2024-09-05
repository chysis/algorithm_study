#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, N;
    cin>>T;
    while(T--){
        cin>>N;
        string str, target;
        cin>>str>>target;
        
        int w=0, b=0;
        for(int i=0; i<str.length(); i++){
            if(str[i]=='W' && target[i]=='B') w++;
            else if(str[i]=='B' && target[i]=='W') b++;
        }
        
        cout<<max(w, b)<<"\n";
    }
}