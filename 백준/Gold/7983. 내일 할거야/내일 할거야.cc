#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int D, T;
        cin>>D>>T;
        arr[i]={T, D}; // comp 생성 방지
    }
    
    sort(arr, arr+N);
    
    int ans=arr[N-1].first;
    for(int i=N-1; i>0; i--){
        if(ans-arr[i].second>arr[i-1].first) ans=arr[i-1].first;
        else ans-=arr[i].second;
    }
    ans-=arr[0].second;
    
    cout<<(ans<=0 ? 0 : ans);
}