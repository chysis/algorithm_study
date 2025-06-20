#include <bits/stdc++.h>
using namespace std;

int A, B, C;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>A>>B>>C;
    int arr[3]={A, B, C};
    sort(arr, arr+3);
    cout<<arr[0]+arr[1]+min(arr[2], arr[0]+arr[1]-1);
}