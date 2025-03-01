#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[100001], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int temp=1;
    for(int i=1; i<N; i++){
        if(arr[i]>=arr[i-1]) temp++;
        else{
            ans=max(ans, temp);
            temp=1;
        }
    }
    ans=max(ans, temp);
    
    temp=1;
    for(int i=1; i<N; i++){
        if(arr[i]<=arr[i-1]) temp++;
        else{
            ans=max(ans, temp);
            temp=1;
        }
    }
    ans=max(ans, temp);
    
    cout<<ans;
}