#include <bits/stdc++.h>
using namespace std;

int N, arr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    sort(arr, arr+N);
    
    for(int k=0; k<=N; k++){
        int moreK=lower_bound(arr, arr+N, k)-arr;
        int temp1=N-moreK; // k번 이상 인용된 논문
        int temp2=upper_bound(arr, arr+N, k)-arr; // k번 이하로 인용된 논문 개수
        if(temp1>=k && temp2>=N-k){
            cout<<k;
            break;
        }
    }
}