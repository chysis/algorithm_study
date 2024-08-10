#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[1001];

bool comp(pair<int, int>& a, pair<int, int>& b){
    return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int T, S;
        cin>>T>>S;
        arr[i]={T, S};
    }
    
    sort(arr, arr+N, comp);
    
    int ans=arr[N-1].second-arr[N-1].first;
    for(int i=N-2; i>=0; i--){
        if(ans<=arr[i].second) ans-=arr[i].first;
        else ans=arr[i].second-arr[i].first;
    }
    
    if(ans<0) cout<<-1;
    else cout<<ans;
}