#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001], dp[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    int s=1, e=1, sum=arr[1];
    int sMax=-1;
    while(s<=N && e<=N){
        if(sum>=K){
            dp[e]=max(dp[e], sMax+sum-K);
            
            // cout<<"s: "<<s<<" "<<"e: "<<e<<" sum: "<<sum<<"\n";
            
            // for(int i=1; i<=N; i++){
            //     cout<<dp[i]<<" ";
            // }
            // cout<<"\n\n";
            
            if(s==e){
                s++;
                e++;
                sum=arr[e];
                sMax=max(sMax, dp[s-1]);
            } else if(s<e){
                s++;
                sum-=arr[s-1];
                sMax=max(sMax, dp[s-1]);
            }
        } else{
            e++;
            sum+=arr[e];
        }
    }
    
    // for(int i=1; i<=N; i++){
    //     cout<<dp[i]<<" ";
    // }
    
    cout<<dp[N];
}