#include <bits/stdc++.h>
#define ll long long
#define INF LLONG_MAX
using namespace std;

int T, N, arr[4001], sum[4001];
ll ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1; i<=N; i++) cin>>arr[i];
        sort(arr+1, arr+N+1);

        for(int i=1; i<=N; i++) sum[i]=sum[i-1]+arr[i];
        
        for(int M=2; M<=N; M++){ // 갚을 날짜 개수
            ll temp=INF;
            for(int i=1; i<=N-M+1; i++){ // 시작 날짜
                ll all=arr[i+M-1]*M;
                ll added=all-(sum[i+M-1]-sum[i-1]);
                temp=min(temp, added);
            }
            ans+=temp;
            temp=INF;
        }
        cout<<ans<<"\n";
        ans=0;
    }
}