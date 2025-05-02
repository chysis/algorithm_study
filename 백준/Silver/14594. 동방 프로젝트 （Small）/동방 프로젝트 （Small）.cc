#include <bits/stdc++.h>
using namespace std;

int N, M, X, Y;
bool arr[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=0; i<M; i++){
        cin>>X>>Y;
        for(int j=X; j<Y; j++){
            arr[j]=true;
        }
    }
    
    int ans=0;
    for(int i=1; i<N; i++){
        if(!arr[i]) ans++;
    }
    
    cout<<ans+1;
}