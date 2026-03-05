#include <bits/stdc++.h>
#define ll long long
#define INF (~0U>>2)
using namespace std;

ll N, K, arr[1000001];

ll getSum(ll end){
    return end * (end+1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    ll s=1, e=1414213562LL, ans=e;
    while(s<=e){
        ll m=(s+e)/2;
        ll sum=getSum(m); // 마지막 급상승부터 0원 될 때까지의 합을 미리 더함
        for(int i=1; i<N; i++){
            ll cnt=arr[i]-arr[i-1];
            cnt=min(m, cnt);
            sum+=getSum(m)-getSum(m-cnt);
            if(sum>=K) break;
        }
        
        if(sum<K) s=m+1;
        else{
            ans=min(ans, m);
            e=m-1;
        }
    }
    
    cout<<ans;
}