#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int s=0, e=0, sum=arr[0], ans=-1;
    while(e<N){
        if(arr[e]>M){
            s=e+1;
            e++;
            sum=arr[e];
        }
        
        if(sum<M){
            ans=max(ans, sum);
            sum+=arr[++e];
        } else if(sum>M){
            sum-=arr[s++];
        } else{
            ans=M;
            break;
        }
    }
    
    cout<<ans;
}