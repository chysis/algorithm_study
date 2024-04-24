#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int arr[10001];

int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    // 기준점
    int p=N-1;
    for(int i=N-1; i>=0; i--){
        if(arr[i]>arr[i-1]){
            p=i-1;
            break;
        }
    }
    
    if(p==-1){
        cout<<-1;
        return 0;
    }
    
    // 기준점보다 오른쪽에 있으면서 기준점보다 큰 값들 중 가장 작은 값
    int targetVal=INF;
    int targetIdx=-1;
    
    for(int i=p; i<N; i++){
        if(arr[i]>arr[p]){
            targetVal=min(targetVal, arr[i]);
            targetIdx=i;
        }
    }
    
    swap(*(arr+p), *(arr+targetIdx));
    sort(arr+p+1, arr+N);
    
    for(int i=0; i<N; i++){
        cout<<arr[i]<<" ";
    }
}