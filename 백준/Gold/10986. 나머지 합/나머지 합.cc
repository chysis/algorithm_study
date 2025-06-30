#include <bits/stdc++.h>
using namespace std;

long long N, M, arr[1000001], cnt[1001], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
        arr[i]%=M;
        if(i>0) arr[i]+=arr[i-1];
    }
    
    for(int i=0; i<N; i++){
        cnt[arr[i]%M]++;
        if(arr[i]%M==0) ans++; // 처음부터 i번째까지의 합
    }
    
    for(int i=0; i<M; i++){
        if(cnt[i]>=2){
            ans+=(cnt[i]*(cnt[i]-1)/2);
        }
    }
    
    cout<<ans;
}