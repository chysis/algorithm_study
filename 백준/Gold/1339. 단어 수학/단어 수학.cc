#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int N, abc[27];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        
        for(int j=0; j<str.length(); j++){
            abc[str[j]-'A']+=pow(10, str.length()-j-1);
        }
    }
    
    sort(abc, abc+26);
    
    int ans=0, num=9;
    for(int i=25; i>=0; i--){
        ans+=abc[i]*(num--);
        if(num<0) break;
    }
    
    cout<<ans;
}