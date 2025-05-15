#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;
bool flag=false;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    if(N==M) return cout<<"YES", 0;
    
    while(N>0){
        if(N%2==1) flag=true;
        if(N<M) break;
        
        if(!flag){
            if(N/2==M) return cout<<"YES", 0;
        } else{
            if(N/2==M || N/2+1==M) return cout<<"YES", 0;
        }
        N/=2;
    }
    
    cout<<"NO";
}