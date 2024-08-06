#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    
    for(int i=0; i<4; i++){
        char c;
        cin>>c;
        if(c=='E') cout<<'I';
        else if(c=='I') cout<<'E';
        else if(c=='S') cout<<'N';
        else if(c=='N') cout<<'S';
        else if(c=='T') cout<<'F';
        else if(c=='F') cout<<'T';
        else if(c=='J') cout<<'P';
        else if(c=='P') cout<<'J';
    }
}