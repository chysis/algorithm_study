#include <iostream>
#include <algorithm>
using namespace std;

int arr[100002], sum[100002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<M; i++){
        int A, B, K;
        cin>>A>>B>>K;
        sum[A]+=K;
        sum[B+1]-=K;
    }
    
    int temp=0;
    for(int i=1; i<=N; i++){
        temp+=sum[i];
        cout<<arr[i]+temp<<" ";
    }
}