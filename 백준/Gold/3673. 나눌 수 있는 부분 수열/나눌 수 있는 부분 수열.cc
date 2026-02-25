#include <bits/stdc++.h>
using namespace std;

int C, D, N, cnt[1000001], ans=0; // 이전까지 등장한 같은 나머지의 구간 시작점 개수
long long arr[50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>C;
    while(C--){
        cin>>D>>N;
        cnt[0]=1;
        for(int i=1; i<=N; i++){
            cin>>arr[i];
            arr[i]+=arr[i-1];
            arr[i]%=D;
            ans+=cnt[arr[i]]++;
        }
        cout<<ans<<"\n";
        ans=0;
        memset(cnt, 0, sizeof(cnt));
    }
}