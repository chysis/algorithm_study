#include <bits/stdc++.h>
using namespace std;

int N, T, P, arr[6], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<6; i++) cin>>arr[i];
    cin>>T>>P;
    
    for(int i=0; i<6; i++) ans+=(arr[i]%T==0 ? arr[i]/T : arr[i]/T+1);
    cout<<ans<<"\n"<<N/P<<" "<<N%P;
}