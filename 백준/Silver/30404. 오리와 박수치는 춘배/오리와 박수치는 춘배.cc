#include <iostream>
using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int ans=0;
    int idx=1, cur=0;
    while(true){
        if(idx==N) break;
        
        if(arr[cur]+K<arr[idx]) {
            ans++;
            cur=idx;
            idx++;
        }
        else{
            idx++;
        }
    }
    
    cout<<ans+1;
}