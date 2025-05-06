#include <iostream>
#define ll long long
using namespace std;

ll N, K;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    
    ll s=-1, e=N/2+1, m;
    while(s+1<e){
        m=(s+e)/2; // 가로로 자른 횟수
        ll temp=(m+1)*(N-m+1);
        if(temp==K){
            cout<<"YES";
            return 0;
        }
        
        if(temp>K) e=m;
        else s=m;
    }
    
    cout<<"NO";
}