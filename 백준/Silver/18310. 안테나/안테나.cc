#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[200001];

bool comp(int a, int b){
    return a<b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N, comp);
    cout<<arr[(N-1)/2];
}