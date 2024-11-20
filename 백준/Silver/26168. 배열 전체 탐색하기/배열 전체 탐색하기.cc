#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

ll arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N);
    
    for(int i=0; i<M; i++){
        int opt;
        cin>>opt;
        
        if(opt==1){
            ll k;
            cin>>k;
            cout<<N-(lower_bound(arr, arr+N, k)-arr)<<"\n";
        } else if(opt==2){
            ll k;
            cin>>k;
            cout<<N-(upper_bound(arr, arr+N, k)-arr)<<"\n";
        } else{
            ll x, y;
            cin>>x>>y;
            int s=lower_bound(arr, arr+N, x)-arr;
            int e=upper_bound(arr, arr+N, y)-arr;
            cout<<e-s<<"\n";
        }
    }
}