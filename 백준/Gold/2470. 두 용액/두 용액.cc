#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long INF = 999999999999;
int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N);
    
    int s=0, e=N-1, sum;
    long long ans=INF;
    int one, two;
    while(s<e){
        sum=arr[s]+arr[e];
        if(ans>abs(sum)){
            ans=abs(sum);
            one=arr[s]; two=arr[e];
        }
        
        if(sum>0) e--;
        else if(sum<0) s++;
        else{
            cout<<arr[s]<<" "<<arr[e];
            return 0;
        }
    }
    
    cout<<one<<" "<<two;
}