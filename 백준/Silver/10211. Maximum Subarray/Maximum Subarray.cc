#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int arr[1001], sum[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        for(int i=1; i<=N; i++){
            cin>>arr[i];
            sum[i]=sum[i-1]+arr[i];
        }
        
        int ans=-INF;
        for(int i=1; i<=N; i++){
            for(int j=0; j<i; j++){
                ans=max(ans, sum[i]-sum[j]);
            }
        }
        
        cout<<ans<<"\n";
    }
}