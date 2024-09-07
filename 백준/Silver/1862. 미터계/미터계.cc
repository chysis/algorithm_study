#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string N;
    int ans=0;
    cin>>N;
    for(int i=0; i<N.length(); i++){
        int num=N[N.length()-1-i]-'0';
        
        if(num>4){
            ans+=(num-1)*pow(9, i);
        } else{
            ans+=(num)*pow(9, i);
        }
    }
    
    cout<<ans;
}