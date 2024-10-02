#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int N, M, arr[5001];
int s, e, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    int mx=-1;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
        mx=max(mx, arr[i]);
    }
    
    s=0, e=ans=mx;
    
    while(s<=e){
        int m=(s+e)/2;
        
        int mx=arr[0], mn=arr[0], cnt=1;
        for(int i=0; i<N; i++){
            mx=max(mx, arr[i]);
            mn=min(mn, arr[i]);
            
            if(mx-mn>m){
                cnt++;
                mx=mn=arr[i];
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