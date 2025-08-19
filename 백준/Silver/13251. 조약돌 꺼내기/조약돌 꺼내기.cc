#include <bits/stdc++.h>
using namespace std;

double N=0, M, K, arr[51], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout<<fixed;
    cout.precision(9);
    
    cin>>M;
    for(int i=0; i<M; i++) {
        cin>>arr[i];
        N+=arr[i];
    }
    cin>>K;
    
    for(int i=0; i<M; i++){
        if(arr[i]<K) continue;
        double temp=1, cnt=K, cur=arr[i], total=N;
        
        while(cnt){
            temp*=(cur--);
            temp/=(total--);
            cnt--;
        }
        ans+=temp;
    }
    cout<<ans;
}