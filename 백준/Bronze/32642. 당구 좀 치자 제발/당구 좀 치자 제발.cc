#include <bits/stdc++.h>
using namespace std;

int N, arr[200001], score[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    score[0]=arr[0]==0 ? -1 : 1;
    for(int i=1; i<N; i++){
        if(arr[i]==0) score[i]=score[i-1]-1;
        else score[i]=score[i-1]+1;
    }
    
    long long ans=0;
    for(int i=0; i<N; i++) ans+=score[i];
    cout<<ans;
}