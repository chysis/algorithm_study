#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N, A, B, ans=0;
pll arr[100001];

bool comp(pll& a, pll& b){
    return a.first>b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    sort(arr, arr+N, comp);

    for(int i=0; i<N; i++){
        ans+=(arr[i].first*(N-i)+arr[i].second);
    }
    cout<<ans;
}