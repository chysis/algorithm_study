#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

pair<int, int> arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    ll sum=0;
    for(int i=0; i<N; i++){
        int X, A;
        cin>>X>>A;
        arr[i]={X, A};
        sum+=A;
    }
    
    sort(arr, arr+N);
    
    ll temp=0;
    for(int i=0; i<N; i++){
        temp+=arr[i].second;
        if(temp>=(double)sum/2){
            cout<<arr[i].first;
            break;
        }
    }
}