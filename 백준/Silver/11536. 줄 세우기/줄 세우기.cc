#include <iostream>
#include <string>
using namespace std;

string arr[21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    bool inc=false;
    bool dec=false;
    
    for(int i=0; i<N-1; i++){
        if(arr[i]<arr[i+1]){
            inc=true;
        } else if(arr[i]>arr[i+1]){
            dec=true;
        }
    }
    
    if(inc && !dec) cout<<"INCREASING";
    else if(!inc && dec) cout<<"DECREASING";
    else cout<<"NEITHER";
}