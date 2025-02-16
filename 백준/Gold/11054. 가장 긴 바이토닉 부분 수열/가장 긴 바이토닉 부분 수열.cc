#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[1001], dpInc[1001], dpDec[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<N; i++){
        dpInc[i]=1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]) dpInc[i]=max(dpInc[i], dpInc[j]+1);
        }
    }
    
    for(int i=N-1; i>=0; i--){
        dpDec[i]=1;
        for(int j=N-1; j>i; j--){
            if(arr[j]<arr[i]) dpDec[i]=max(dpDec[i], dpDec[j]+1);
        }
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        ans=max(ans, dpInc[i]+dpDec[i]-1);
    }
    cout<<ans;
}