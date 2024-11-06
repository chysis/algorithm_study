#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string N;
    cin>>N;
    for(int i=0; i<N.length()/10+1; i++){
        cout<<N.substr(i*10, 10)<<"\n";
    }
}