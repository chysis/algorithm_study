#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001], sum[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    for(int i=N+1; i<=2*N; i++){
        arr[i]=arr[i-N];
    }
    
    for(int i=1; i<=2*N; i++){
        sum[i]=sum[i-1]+arr[i];
    }
    
    int ans=-1;
    for(int i=K; i<=2*N; i++){
        ans=max(ans, sum[i]-sum[i-K]);
    }
    
    cout<<ans;
}