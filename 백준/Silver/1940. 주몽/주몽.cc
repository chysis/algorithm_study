#include <iostream>
#include <algorithm>
using namespace std;

int arr[15001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, ans=0;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);
    
    int s=0, e=N-1, temp;
    while(s<e){
        temp=arr[s]+arr[e];
        if(temp>M){
            e--;
        }
        else if(temp<M){
            s++;
        }
        else{
            ans++;
            s++;
            e--;
        }
    }
    
    cout<<ans;
}