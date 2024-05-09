#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int L, H;
        cin>>L>>H;
        arr[i]={L, H};
    }
    
    sort(arr, arr+N);
    
    int ans=0;
    
    for(int i=arr[0].first; i<=arr[N-1].first; i++){
        int leftMax=-1, rightMax=-1;
        
        for(int j=0; j<N; j++){
            if(arr[j].first<=i) leftMax=max(leftMax, arr[j].second);
            else break;
        }
        
        for(int j=0; j<N; j++){
            if(arr[j].first>=i) rightMax=max(rightMax, arr[j].second);
        }
        
        ans+=min(leftMax, rightMax);
    }
    
    cout<<ans;
}