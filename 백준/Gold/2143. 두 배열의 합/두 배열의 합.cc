#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T, N, M, arr1[1001], arr2[1001], ans=0;
unordered_map<ll, ll> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    cin>>N;
    for(int i=1; i<=N; i++) cin>>arr1[i];
    cin>>M;
    for(int i=1; i<=M; i++) cin>>arr2[i];
    
    // 누적합 계산
    for(int i=2; i<=N; i++) arr1[i]+=arr1[i-1];
    for(int i=2; i<=M; i++) arr2[i]+=arr2[i-1];
    
    // 모든 경우를 뽑은 다음 더하면서 세면 너무 오래 걸림
    // O(N^2)까지는 가능하므로 arr1에서 모든 경우 뽑으면서 T-sum1이 arr2에서 나올 수 있는지 확인
    
    // arr2에서 나올 수 있는 합들을 map으로 따로 저장 -> 개수를 바로 알 수 있게
    for(int i=1; i<=M; i++){
        for(int j=1; j<=i; j++){
            um[arr2[i]-arr2[j-1]]++;
        }
    }
    
    // arr1에서 모든 경우 탐색 
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            ll sum1=arr1[i]-arr1[j-1];
            ans+=um[T-sum1];
        }
    }
    
    cout<<ans;
}