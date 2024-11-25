#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

ll arr[100001], sum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int P, A, B;
    cin>>P;
    for(int i=0; i<P; i++){
        cin>>arr[i];
        if(i>0) sum[i]=sum[i-1]+arr[i];
        else sum[i]=arr[i];
    }
    cin>>A>>B;
    
    if(A<0){
        int cnt=abs(A)/P+1;
        A+=P*cnt;
        B+=P*cnt;
    }
    
    int aD=A/P, aR=A%P;
    int bD=B/P, bR=B%P;
    
    ll ans=0;
    if(aD!=bD){
        ans+=sum[P-1]-sum[aR-1];
        ans+=(bD-aD-1)*sum[P-1];
        ans+=sum[bR-1];
    } else{
        ans+=sum[bR-1]-sum[aR-1];
    }
    
    cout<<ans;
}