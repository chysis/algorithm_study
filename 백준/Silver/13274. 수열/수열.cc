#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

ll arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    sort(arr+1, arr+N+1);
    
    while(K--){
        ll L, R, X;
        cin>>L>>R>>X;
        for(int i=L; i<=R; i++){
            arr[i]+=X;
        }
        
        sort(arr+1, arr+N+1);
    }
    
    for(int i=1; i<=N; i++){
        cout<<arr[i]<<" ";
    }
}