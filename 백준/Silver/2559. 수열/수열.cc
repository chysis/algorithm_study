#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int arr[100001];
int sum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int temp=0;
    for(int i=0; i<K; i++){
        temp+=arr[i];
    }
    sum[0]=temp;
    
    for(int i=1; i<N-K+1; i++){
        sum[i]=sum[i-1]-arr[i-1]+arr[i+K-1];
    }
    
    int ans=-INF;
    for(int i=0; i<N-K+1; i++){
        ans=max(ans, sum[i]);
    }
    
    cout<<ans;
}