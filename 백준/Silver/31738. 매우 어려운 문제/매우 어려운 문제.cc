#include <iostream>

#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, ans=1;
    int M;
    cin>>N>>M;
    if(N>=M) ans=0;
    else{
        for(ll i=N; i>0; i--){
            ans*=i;
            ans%=M;
            
            if(ans==0) break;
        }
    }
    
    cout<<ans;
}