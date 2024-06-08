#include <iostream>
#include <string>
using namespace std;

int arr[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        
        int p=0;
        if(str[p]=='B' || str[p]=='C' || str[p]=='D' || str[p]=='E' || str[p]=='F'){
            p++;
        }
        
        if(str[p]!='A'){
            cout<<"Good\n";
            continue;
        }
        
        while(str[p]=='A') p++;
        
        if(str[p]!='F'){
            cout<<"Good\n";
            continue;
        }
        
        while(str[p]=='F') p++;
        
        if(str[p]!='C'){
            cout<<"Good\n";
            continue;
        }
        
        while(str[p]=='C') p++;
        
        if(str[p]=='A' || str[p]=='B' || str[p]=='C' || str[p]=='D' || str[p]=='E' || str[p]=='F'){
            p++;
        }
        
        if(str.length()!=p){
            cout<<"Good\n";
            continue;
        }
        
        cout<<"Infected!\n";
        
    }
}