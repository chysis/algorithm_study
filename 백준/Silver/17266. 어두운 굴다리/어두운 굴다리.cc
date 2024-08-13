#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans=100000;
int arr[100001];

bool cover(int h){
    if(arr[0]-h>0) return false;
    if(arr[M-1]+h<N) return false;
    
    for(int i=1; i<M-1; i++){
        if(arr[i]-h>arr[i-1]+h) return false;
        if(arr[i]+h<arr[i+1]-h) return false;
    }
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>arr[i];
    }
    
    int s=1, e=N;
    while(s<=e){
        int m=(s+e)/2;
        
        if(cover(m)) {
            ans=min(ans, m);
            e=m-1;
        } else{
            s=m+1;    
        }
    }
    
    cout<<ans;
}