#include <iostream>
#include <algorithm>
using namespace std;

long long ans=0;
int arr[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);
    
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N-1; j++){
            int sum=arr[i]+arr[j];
            int lb=lower_bound(arr+j+1, arr+N, -sum)-(arr+j+1);
            int ub=upper_bound(arr+j+1, arr+N, -sum)-(arr+j+1);
            ans+=(ub-lb);
        }
    }
    
    cout<<ans;
}