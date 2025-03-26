#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

// dp[i]: 사이즈가 i인 사면체를 만드는 데 필요한 대포알의 개수
int N, dp[121], dpp[300001]; // dpp[i]: i개의 대포알로 만들 수 있는 사면체의 최소 개수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=120; i++){
        for(int j=1; j<=i; j++){
            dp[i]+=(j*(i-j+1));
        }
    }
    
    for(int i=0; i<=N; i++){
        dpp[i]=INF;
    }
    
    for(int i=1; i<=120; i++){
        dpp[dp[i]]=1;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=120; j++){
            if(i<dp[j]) break;
            dpp[i]=min(dpp[i], dpp[i-dp[j]]+1);
        }
    }
    
    cout<<dpp[N];
}