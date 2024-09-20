#include <iostream>
using namespace std;

int N, K, arr[100001];
int s=0, e=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        e+=arr[i];
    }
    
    while(s<=e){
        int m=(s+e)/2;
        int sum=0, cnt=0;
        
        for(int i=0; i<N; i++){
            sum+=arr[i];
            if(sum>=m){
                cnt++;
                sum=0;
            }
        }
        
        if(cnt>=K) s=m+1;
        else e=m-1;
    }
    
    cout<<e;
}