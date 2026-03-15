#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, B, C, arr[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    cin>>B>>C;
    
    ll ans=0;
    for(int i=0; i<N; i++){
        int temp=1;
        arr[i]-=B; // 총감독관
        if(arr[i]<=0){
            ans+=temp;
            continue;
        }
        
        temp+=arr[i]/C; // 부감독관
        if(arr[i]%C!=0) temp++;
        
        ans+=temp;
    }
    cout<<ans;
}