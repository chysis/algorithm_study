#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int k=N-1, m=N-1;
    while(k>0 && arr[k-1]<arr[k]) k--;
    
    if(k==0) {
        cout<<-1;
        return 0;
    }
    else{
        while(arr[k-1]<arr[m]) m--;
        
        swap(arr[k-1], arr[m]);
        
        reverse(arr+k, arr+N);
    }
    
    for(int i=0; i<N; i++){
        cout<<arr[i]<<" ";
    }
}