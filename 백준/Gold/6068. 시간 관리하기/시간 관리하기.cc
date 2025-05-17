#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int N, T, S;
pii arr[1001];

bool comp(pii& a, pii& b){
    return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>T>>S;
        arr[i]={T, S};
    }
    
    sort(arr, arr+N, comp);
    
    int ans=arr[N-1].second-arr[N-1].first;
    for(int i=N-2; i>=0; i--){
        if(ans<arr[i].second) ans-=arr[i].first;
        else ans=arr[i].second-arr[i].first;
    }
    
    cout<<(ans<0 ? -1 : ans) ;
}