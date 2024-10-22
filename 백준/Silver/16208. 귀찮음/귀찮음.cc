#include <iostream>
using namespace std;

int arr[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            ans+=(arr[i]*arr[j]);
        }
    }
    
    cout<<ans;
}