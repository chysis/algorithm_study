#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, L;
    cin>>N>>L;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N);
    
    for(int i=0; i<N; i++){
        if(arr[i]<=L) L++;
    }
    cout<<L;
}