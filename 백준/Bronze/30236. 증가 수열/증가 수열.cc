#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        
        for(int i=0; i<N; i++){
            cin>>arr[i];  
        }
        
        int cnt=1;
        for(int i=0; i<N; i++){
            if(arr[i]==cnt) cnt++;
            cnt++;
        }
        cout<<cnt-1<<"\n";
    }
}