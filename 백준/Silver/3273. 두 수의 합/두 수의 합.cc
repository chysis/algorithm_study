#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, X, cnt=0;
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    cin>>X;
    sort(arr, arr+N);
    
    int start=0;
    int end=N-1;
    do{
        int partial_sum=arr[start]+arr[end];
        if(partial_sum==X) cnt++;
        if(partial_sum<X)  partial_sum-=arr[start++];
        else if(partial_sum>=X) partial_sum-=arr[end--];
    }
    while(start<end);
    cout<<cnt<<"\n";
}