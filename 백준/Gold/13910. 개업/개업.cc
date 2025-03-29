#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, M, num, dp[10001]; // dp[i]: 짜장면 i그릇을 처리하기 위해 해야 하는 최소 요리 횟수
vector<int> arr, wok;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=1; i<=N; i++){
        dp[i]=INF;
    }
    
    for(int i=0; i<M; i++){
        cin>>num;
        arr.push_back(num);
        wok.push_back(num);
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(i==j) continue;
            wok.push_back(arr[i]+arr[j]);
        }
    }
    
    for(auto a: wok){
        if(a<=10000) dp[a]=1;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<wok.size(); j++){
            if(i-wok[j]>=0) dp[i]=min(dp[i], dp[i-wok[j]]+1);
        }
    }
    
    cout<<(dp[N]==INF ? -1 : dp[N]);
}