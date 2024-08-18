#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

ll sum=0, arr[200001], isOn[200001], dp[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<N; i++){
        cin>>isOn[i];
        if(isOn[i]) sum+=arr[i];
    }
    
    for(int i=0; i<N; i++){
        if(isOn[i]){
            dp[i]=max(-arr[i], dp[i-1]-arr[i]);
        } else {
            dp[i]=max(arr[i], dp[i-1]+arr[i]);
        }
    }
    
    ll maxV=dp[0];
    for(int i=0; i<N; i++){
        maxV=max(maxV, dp[i]);
    }
    
    cout<<maxV+sum;
}