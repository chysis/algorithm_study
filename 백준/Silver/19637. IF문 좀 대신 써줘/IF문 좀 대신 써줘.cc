#include <bits/stdc++.h>
using namespace std;

int N, M, num, val[100001];
string title[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>title[i]>>val[i];
    }
    
    for(int i=0; i<M; i++){
        cin>>num;
        int idx=lower_bound(val, val+N, num)-val;
        cout<<title[idx]<<"\n";
    }
}