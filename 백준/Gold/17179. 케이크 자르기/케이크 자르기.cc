#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, L;
    cin>>N>>M>>L;
    
    arr[0]=0, arr[M+1]=L;
    for(int i=1; i<=M; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        
        int s=0, e=L, ans=0;
        while(s<=e){
            int m=(s+e)/2;
            
            int cur=arr[0], cnt=0;
            for(int i=1; i<=M+1; i++){
                if(arr[i]-cur>=m){
                    cnt++;
                    cur=arr[i];
                }
            }
            
            if(cnt>num){
                ans=max(ans, m);
                s=m+1;
            } else{
                e=m-1;
            }
        }
        
        cout<<ans<<"\n";
    }
}