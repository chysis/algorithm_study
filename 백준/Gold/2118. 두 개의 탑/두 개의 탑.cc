#include <bits/stdc++.h>
using namespace std;

int N, arr[50001], sum[50001], total=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
        total+=arr[i];
    }
    
    int s=1, e=2, ans=0;
    while(s<N){
        int d=sum[e-1]-sum[s-1];
        if(d>total/2){
            ans=max(ans, total-d);
            s++;
        }else{
            ans=max(ans, d);
            if(e<N) e++;
            else s++;
        }
    }
    cout<<ans;
}