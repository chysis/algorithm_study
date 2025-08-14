#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll N, M, K, X, Y, A, B;
pii arr[100001];

bool comp(pii& a, pii& b){
    return a.first*X-a.second*Y<b.first*X-b.second*Y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K>>X>>Y;
    for(int i=0; i<N; i++){
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    sort(arr, arr+N, comp);
    
    ll nor=K, rap=K;
    for(int i=0; i<M; i++){
        nor+=arr[i].first;
        rap-=arr[i].second;
    }
    cout<<nor*X+rap*Y;
}