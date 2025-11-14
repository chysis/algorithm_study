#include <bits/stdc++.h>
using namespace std;

int N;
double arr[100001], sum=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout<<fixed;
    cout.precision(5);
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i], sum+=arr[i];
    double me=*max_element(arr, arr+N);
    cout<<me+(sum-me)/2;
}