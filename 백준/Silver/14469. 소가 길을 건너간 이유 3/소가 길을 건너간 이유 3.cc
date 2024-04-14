#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int A, B;
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    sort(arr, arr+N);
    
    int ans=arr[0].first+arr[0].second;
    for(int i=1; i<N; i++){
        if(ans>arr[i].first) ans+=arr[i].second;
        else ans=arr[i].first+arr[i].second;
    }
    
    cout<<ans;
}