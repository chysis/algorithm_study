#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    cout<<"YES\n";
    
    if(N==3){
        cout<<"3 1 2";
        return 0;
    }
    
    int arr[4]={1, 2, 4, 3};
    for(int i=0; i<N; i++){
        cout<<arr[i%4]+4*(i/4)<<" ";
    }
}