#include <bits/stdc++.h>
using namespace std;

int N, A, D, G, ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A>>D>>G;
        int temp=0;
        temp=A*(D+G);
        if(A==D+G) temp*=2;
        ans=max(ans, temp);
    }
    cout<<ans;
}