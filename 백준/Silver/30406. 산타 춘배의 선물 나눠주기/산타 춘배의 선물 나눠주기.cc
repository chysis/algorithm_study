#include <iostream>
#include <algorithm>
using namespace std;

int arr[4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        arr[num]++;
    }
    
    int ans=0;
    if(arr[0]<arr[3]){
        ans+=3*arr[0];
        arr[3]-=arr[0];
        arr[0]=0;
    } else{
        ans+=3*arr[3];
        arr[0]-=arr[3];
        arr[3]=0;
    }
    
    if(arr[1]<arr[2]){
        ans+=3*arr[1];
        arr[2]-=arr[1];
        arr[1]=0;
    } else{
        ans+=3*arr[2];
        arr[1]-=arr[2];
        arr[2]=0;
    }
    
    if(arr[0]<arr[2]){
        ans+=2*arr[0];
        arr[2]-=arr[0];
        arr[0]=0;
    } else{
        ans+=2*arr[2];
        arr[0]-=arr[2];
        arr[2]=0;
    }
    
    if(arr[1]<arr[3]){
        ans+=2*arr[1];
        arr[3]-=arr[1];
        arr[1]=0;
    } else{
        ans+=2 *arr[3];
        arr[1]-=arr[3];
        arr[3]=0;
    }
    
    if(arr[0]<arr[1]){
        ans+=arr[0];
        arr[1]-=arr[0];
        arr[0]=0;
    } else{
        ans+=arr[1];
        arr[0]-=arr[1];
        arr[1]=0;
    }
    
    if(arr[2]<arr[3]){
        ans+=arr[2];
        arr[3]-=arr[2];
        arr[2]=0;
    } else {
        ans+=arr[3];
        arr[2]-=arr[3];
        arr[3]=0;
    }
    
    cout<<ans;
}