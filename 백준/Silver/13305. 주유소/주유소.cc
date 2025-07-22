#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, dist[100001], arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N-1; i++) cin>>dist[i];
    for(int i=0; i<N; i++) cin>>arr[i];
    
    ll cur=arr[0], temp=dist[0], ans=0;
    for(int i=1; i<N-1; i++){
        if(arr[i]<cur){
            ans+=temp*cur;
            cur=arr[i];
            temp=dist[i];
        }else{
            temp+=dist[i];
        }
    }
    ans+=temp*cur;
    cout<<ans;
}