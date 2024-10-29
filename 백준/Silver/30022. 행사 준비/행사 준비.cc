#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> arr[100001];

bool comp(pair<int, int>& a, pair<int, int>& b){
    return (a.second-a.first)<(b.second-b.first);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, A, B;
    cin>>N>>A>>B;
    for(int i=0; i<N; i++){
        int p, q;
        cin>>p>>q;
        arr[i]={p, q};
    }
    
    sort(arr, arr+N, comp);
    
    long long ans=0;
    for(int i=0; i<A; i++){
        ans+=arr[N-1-i].first;
    }
    
    for(int i=0; i<B; i++){
        ans+=arr[i].second;
    }
    
    cout<<ans;
}