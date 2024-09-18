#include <iostream>
#include <algorithm>

#define ll long long
#define INF (~0U>>2)
using namespace std;

int arr[100001];
ll N, P, Q, R, S;
int s=1, e=109999, ans=INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    cin>>P>>Q>>R>>S;
    
    while(s<=e){
        int m=(s+e)/2;
        
        ll sum=0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
            if(arr[i]>m+R){
                sum-=P;
            } else if(arr[i]<m){
                sum+=Q;
            }
        }
        
        if(sum>=S){
            ans=min(ans, m);
            e=m-1;
        } else{
            s=m+1;
        }
    }
    
    cout<<(ans==INF ? -1 : ans);
}