#include <bits/stdc++.h>
using namespace std;

int N, K, arr[10001], cnt=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    for(int i=N-1; i>=1; i--){
        for(int j=0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                cnt++;
                swap(arr[j], arr[j+1]);
            }
            
            if(cnt==K){
                for(int k=0; k<N; k++) cout<<arr[k]<<" ";
                return 0;
            }
        }
    }
    cout<<-1;
}