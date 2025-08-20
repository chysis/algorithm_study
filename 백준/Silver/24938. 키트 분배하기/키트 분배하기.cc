#include <bits/stdc++.h>
using namespace std;

int N, arr[200001], total=0, ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i], total+=arr[i];
    
    int target=total/N;

    for(int i=0; i<N-1; i++){
        if(arr[i]<target){
            int diff=target-arr[i];
            ans+=diff;
            arr[i]=target;
            arr[i+1]-=diff;
        } else if(arr[i]>target){
            int diff=arr[i]-target;
            ans+=diff;
            arr[i]=target;
            arr[i+1]+=diff;
        }
    }
    cout<<ans;
}