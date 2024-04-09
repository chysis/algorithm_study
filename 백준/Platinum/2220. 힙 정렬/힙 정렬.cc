#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    
    arr[1]=1;
    for(int i=2; i<=N; i++){
        arr[i]=i;
        
        swap(arr[i], arr[i-1]);
        
        for(int j=i-1; j>1; j/=2){
            swap(arr[j], arr[j/2]);
        }
    } 
    
    for(int i=1; i<=N; i++){
        cout<<arr[i]<<" ";
    }
}