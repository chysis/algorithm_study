#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int ans=0;
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        if(str=="Poblano"){
            ans+=1500;
        } else if(str=="Mirasol"){
            ans+=6000;
        } else if(str=="Serrano"){
            ans+=15500;
        } else if(str=="Cayenne"){
            ans+=40000;
        } else if(str=="Thai"){
            ans+=75000;
        } else if(str=="Habanero"){
            ans+=125000;
        }
    }
    
    cout<<ans;
}