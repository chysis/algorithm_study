#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int L, N, K, arr[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>L>>N>>K;
    arr[0]=0, arr[N+1]=L;
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }

    int diff=-1;
    for(int i=1; i<=N+1; i++){
        diff=max(diff, arr[i]-arr[i-1]);
    }
    
    int s=diff, e=L, ans=L;
    
    while(s<=e){
        int m=(s+e)/2;
        int cnt=0, cur=0;
        
        for(int i=1; i<=N+1; i++){
            if(arr[i]-cur>m){
                cnt++;
                if(arr[i]-cur==m) cur=arr[i];
                else cur=arr[i-1];
            }
        }
        
        if(cnt<=K){
            ans=min(ans, m);
            e=m-1;
        } else {
            s=m+1;
        }
    }
    
    cout<<ans;
}