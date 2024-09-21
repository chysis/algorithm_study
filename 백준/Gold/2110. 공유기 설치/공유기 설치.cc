#include <iostream>
#include <algorithm>

#define INF (~0U>>2)
using namespace std;

int N, C, arr[200001];
int s, e;

int main()
{
    cin>>N>>C;
    int mx=-1, mn=INF;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    sort(arr, arr+N);
    s=1, e=arr[N-1]-arr[0];
    
    while(s<=e){
        int m=(s+e)/2;
        
        int prev=arr[0], cnt=1;
        for(int i=1; i<N; i++){
            if(arr[i]-prev>=m){
                cnt++;
                prev=arr[i];
            }
        }
        
        if(cnt>=C) s=m+1;
        else e=m-1;
    }
    
    cout<<e;
}