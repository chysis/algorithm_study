#include <iostream>
using namespace std;
int N, num, arr[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(int i=1; i<=N; i++){
       cin>>num;
       arr[num]=i;
    }
    int ans=0;
    for(int i=1; i<=N; i++){
        if(arr[i]<arr[i-1]) ans++;
    }
    cout<<ans;
}