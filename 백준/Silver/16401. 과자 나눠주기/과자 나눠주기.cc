#include <iostream>
#include <algorithm>
using namespace std;

int M, N, arr[1000001];
int s=1, e=-1, ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>M>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        e=max(e, arr[i]);
    }
    
    while(s<=e){
        int m=(s+e)/2;
        int cnt=0;
        
        for(int i=0; i<N; i++){
            if(arr[i]<m) continue;
            
            cnt+=arr[i]/m;
            if(cnt>=M) break;
        }
        
        if(cnt<M) e=m-1;
        else {
            s=m+1;
            ans=m;
        }
    }
    
    cout<<ans;
}