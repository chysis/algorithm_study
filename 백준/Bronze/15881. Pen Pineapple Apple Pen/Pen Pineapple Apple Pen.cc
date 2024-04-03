#include <iostream>
#include <string>
using namespace std;

string target="pPAp";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    string str;
    cin>>str;
    
    int ans=0;
    for(int i=0; i<N-3; i++){
        if(str.substr(i, 4)==target){
            ans++;
            i+=3;
        }
    }
    cout<<ans;
}