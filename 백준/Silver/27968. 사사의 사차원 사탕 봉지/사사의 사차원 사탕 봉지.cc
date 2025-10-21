#include <bits/stdc++.h>
using namespace std;

long long N, M, num, arr[300001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=1; i<=M; i++) cin>>arr[i];
    for(int i=1; i<=M; i++){
        arr[i]+=arr[i-1];
    }
    
    for(int i=0; i<N; i++){
        cin>>num;
        int pos=lower_bound(arr+1, arr+M+1, num)-arr;
        if(pos>M) cout<<"Go away!\n";
        else cout<<pos<<"\n";
    }
}