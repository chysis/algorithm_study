#include <iostream>
#include <algorithm>

#define ll long long
#define INF 10000000000000
using namespace std;

ll arr[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int ans=0;
    for(int i=1; i<N; i++){
        if(M>abs(arr[i]-arr[i-1])){
            arr[i]+=INF;
            ans++;
        }
    }
    
    cout<<ans;
}