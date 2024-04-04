#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

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
    
    for(int i=N-1; i>=1; i--){
        int num=arr[i];
        for(int j=i-1; j>=0; j--){
            int target=arr[i]-arr[j];
        
            int s=0, e=j, sum;
            while(s<=e){
                sum=arr[s]+arr[e];
                if(sum>target){
                    e--;
                }
                else if(sum<target){
                    s++;
                }
                else{
                    cout<<num;
                    return 0;
                }
            }
        }
    }
}