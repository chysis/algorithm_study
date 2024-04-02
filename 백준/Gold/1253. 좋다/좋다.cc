#include <iostream>
#include <algorithm>
using namespace std;

int arr[2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N);
    
    int ans=0;
    for(int i=0; i<N; i++){
        int s=0, e=N-1, sum;
        while(s<e){
            if(i==s) s++;
            if(i==e) e--;
            if(s>=e) break;
            
            sum=arr[s]+arr[e];
            if(sum==arr[i]){
                ans++;
                break;
            } else if(sum<arr[i]){
                s++;
            } else if(sum>arr[i]){
                e--;
            }
        }
    }
    
    cout<<ans;
}