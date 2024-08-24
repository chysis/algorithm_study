#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[50005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    arr[0]=-1;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    arr[N+1]=-1;
    
    for(int i=1; i<=N; i++){
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]) cout<<i<<"\n";
    }
}