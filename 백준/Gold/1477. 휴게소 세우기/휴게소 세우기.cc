#include <iostream>
#include <algorithm>
using namespace std;

int arr[55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, L;
    cin>>N>>M>>L;
    
    arr[0]=0, arr[N+1]=L;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    sort(arr+1, arr+N+1);
    
    int s=1, e=L, ans=L;
    while(s<=e){
        int m=(s+e)/2;
        int cnt=0;
        
        for(int i=1; i<=N+1; i++){
            if((arr[i]-arr[i-1])%m==0){
                cnt+=(((arr[i]-arr[i-1])/m)-1);
            } else{
                cnt+=((arr[i]-arr[i-1])/m);
            }
        }
        
        if(cnt>M){
            s=m+1;
        } else{
            ans=min(ans, m);
            e=m-1;
        }
    }
    
    cout<<ans;
}