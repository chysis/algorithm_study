#include <iostream>
using namespace std;

int N, ans=0, arr[51];

bool isAllZero(){
    for(int i=0; i<N; i++){
        if(arr[i]!=0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    while(true){
        if(isAllZero()) break;
        
        for(int i=0; i<N; i++){
            if(arr[i]%2!=0){
                arr[i]--;
                ans++;
            }
        }
        
        if(isAllZero()) break;
        
        for(int i=0; i<N; i++){
            arr[i]/=2;
        }
        ans++;
    }
    
    cout<<ans;
}