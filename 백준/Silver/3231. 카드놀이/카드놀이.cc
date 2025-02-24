#include <iostream>
using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
       int num;
       cin>>num;
       arr[num]=i;
    }
    
    int ans=0;
    for(int i=1; i<=N; i++){
        if(arr[i]<arr[i-1]) ans++;
    }
    
    cout<<ans;
}