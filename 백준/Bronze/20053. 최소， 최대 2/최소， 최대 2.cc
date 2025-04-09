#include <bits/stdc++.h>
using namespace std;

int T, N, arr[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        
        cout<<*min_element(arr, arr+N)<<" "<<*max_element(arr, arr+N)<<"\n";
    }
}