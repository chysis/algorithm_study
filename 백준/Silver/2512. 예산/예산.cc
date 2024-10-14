#include <iostream>
#include <algorithm>

#define INF (~0U>>2)
#define ll long long
using namespace std;

ll N, M;
int arr[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    int mx=-1;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        mx=max(mx, arr[i]);
    }
    cin>>M;
    
    int s=0, e=mx, ans=0;
    while(s<=e){
        int m=(s+e)/2;
        
        ll sum=0;
        for(int i=0; i<N; i++){
            if(arr[i]<=m) sum+=arr[i];
            else sum+=m;
        }
        
        if(sum>M){
            e=m-1;
        } else{
            ans=max(ans, m);
            s=m+1;
        }
    }
    
    cout<<ans;
}