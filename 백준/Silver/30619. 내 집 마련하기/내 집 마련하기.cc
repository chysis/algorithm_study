#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int initIdx[301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        initIdx[arr[i]]=i;
    }
    
    cin>>M;
    for(int i=0; i<M; i++){
        int L, R;
        cin>>L>>R;
        
        int idx[301];
        for(int i=1; i<=N; i++){
            idx[i]=initIdx[i];
        }
        
        sort(idx+L, idx+R+1);
        
        int ans[301];
        for(int i=1; i<=N; i++){
            ans[idx[i]]=i;
        }
        
        for(int i=1; i<=N; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}