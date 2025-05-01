#include <bits/stdc++.h>
using namespace std;

int N, M, arr[11], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    cin>>M;
    for(int i=0; i<M; i++){
        int num;
        cin>>num;
        ans+=arr[num];
    }
    cout<<ans;
}