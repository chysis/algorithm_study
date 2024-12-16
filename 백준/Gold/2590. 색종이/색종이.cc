#include <iostream>
#include <algorithm>
using namespace std;

int arr[7];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=1; i<=6; i++){
        cin>>arr[i];
    }
    
    int ans=0;
    
    ans+=arr[6];
    
    ans+=arr[5];
    arr[1]-=min(arr[1], arr[5]*11);
    
    ans+=arr[4];
    for(int i=0; i<arr[4]; i++){
        if(arr[1]==0 && arr[2]==0) continue;
        
        if(arr[2]>=5) arr[2]-=5;
        else{
            arr[1]-=min(arr[1], (5-arr[2])*4);
            arr[2]=0;
        }
    }
    
    if(arr[3]>=4){
        ans+=(arr[3]/4);
        arr[3]%=4;
    }
    
    if(arr[3]==3){
        ans++;
        arr[2]-=min(arr[2], 1);
        arr[1]-=min(arr[1], 5);
    } else if(arr[3]==2){
        ans++;
        arr[1]-=min(arr[1], 18-min(arr[2], 3)*4);
        arr[2]-=min(arr[2], 3);
    } else if(arr[3]==1){
        ans++;
        arr[1]-=min(arr[1], 27-min(arr[2], 5)*4);
        arr[2]-=min(arr[2], 5);
    }
    
    if(arr[2]>=9){
        ans+=(arr[2]/9);
        arr[2]%=9;
    }
    
    if(arr[2]!=0){
        ans++;
        arr[1]-=min(arr[1], (9-arr[2])*4);
        arr[2]=0;
    }
    
    if(arr[1]>=36){
        ans+=arr[1]/36;
        arr[1]%=36;
    }

    if(arr[1]!=0) ans++;
    
    cout<<ans;
}