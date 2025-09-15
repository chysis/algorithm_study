#include <bits/stdc++.h>
using namespace std;

int N, X, Y;
pair<int, int> arr[200001],  arr2[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>X>>Y;
        arr[i]={X, Y};
    }
    for(int i=0; i<N; i++){
        cin>>X>>Y;
        arr2[i]={X, Y};
    }
    
    sort(arr, arr+N);
    sort(arr2, arr2+N);
    cout<<arr2[0].first-arr[0].first<<" "<<arr2[0].second-arr[0].second;
}