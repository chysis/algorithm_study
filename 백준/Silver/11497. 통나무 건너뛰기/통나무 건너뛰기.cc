#include <iostream>
#include <algorithm>
#define INF (~0U>>2)
using namespace std;

int T, S, arr[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>S;
        for(int i=0; i<S; i++){
            cin>>arr[i];
        }
        
        sort(arr, arr+S);
        
        int ans=-1, prev=-1;
        for(int i=0; i<S; i+=2){
            if(prev==-1) prev=arr[i];
            else {
                ans=max(ans, abs(prev-arr[i]));
                prev=arr[i];
            }
        }
        
        for(int i=(S%2==0 ? S-1 : S-2); i>=0; i-=2){
            ans=max(ans, abs(prev-arr[i]));
            prev=arr[i];
        }
        
        ans=max(ans, abs(arr[0]-arr[1]));
        
        cout<<ans<<"\n";
    }
}