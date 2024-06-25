#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    cout<<"YES\n";
    
    int arr[4]={1, 2, 4, 3};
    if(N%4==2){
        for(int i=1; i<=N; i++){
            if(i%4==1) cout<<i+1<<" ";
            else if(i%4==2) cout<<i-1<<" ";
            else if(i%4==3) cout<<i<<" ";
            else if(i%4==0) cout<<i<<" ";
        }
    } else{
        for(int i=1; i<=N; i++){
            if(i%4==1) cout<<i<<" ";
            else if(i%4==2) cout<<i+1<<" ";
            else if(i%4==3) cout<<i-1<<" ";
            else if(i%4==0) cout<<i<<" ";
        }
    }
}