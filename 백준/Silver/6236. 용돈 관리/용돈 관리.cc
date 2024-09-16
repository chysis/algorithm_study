#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[100001];
int s=-1, e=0, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        e+=arr[i];
        s=max(s, arr[i]);
    }

    while(s<=e){
        int m=(s+e)/2;
        
        int temp=m, cnt=1;
        for(int i=0; i<N; i++){
            if(temp<arr[i]){
                temp=m;
                cnt++;
            }
            temp-=arr[i];
        }
        
        if(cnt>M) s=m+1;
        else{
            ans=m;
            e=m-1;
        }
    }
    
    cout<<ans;
}