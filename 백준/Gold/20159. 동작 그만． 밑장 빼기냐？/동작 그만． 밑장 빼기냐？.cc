#include <bits/stdc++.h>
using namespace std;

int N, arr[100001], sumOdd[50001], sumEven[50001], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++) cin>>arr[i];
    
    for(int i=1; i<=N; i+=2) sumOdd[i/2+1]=sumOdd[i/2]+arr[i];
    for(int i=2; i<=N; i+=2) sumEven[i/2]=sumEven[i/2-1]+arr[i];
    
    // 밑장빼기 안 하는 경우
    ans=sumOdd[N/2];
    
    // i일 때 밑장빼기
    for(int i=1; i<=N; i++){
        int temp=0;
        
        if(i%2==1){
            temp+=sumOdd[i/2]; // sumOdd는 1 3 5 -> 1 2 3
            temp+=arr[N];
            temp+=sumEven[N/2 - 1]-sumEven[i/2];
        }else{
            temp+=sumOdd[i/2];
            temp+=sumEven[N/2 - 1]-sumEven[i/2-1];
        }
        
        ans=max(ans, temp);
    }
    
    cout<<ans;
}