#include <bits/stdc++.h>
#define MOD 900528
using namespace std;

int dp[1000001], ans=0; // dp[i]: i자리 암호 개수 % MOD
string P, T;
map<string, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>P>>T;
    // cba라면 c: 0, b: 1, a: 2로 매핑
    for(int i=0; i<P.length(); i++){
        m[P.substr(i, 1)]=i; // 인덱스이자, 해당 문자 이전에 몇 개 존재하는지 의미
    }
    
    // 암호 길이 - 1까지의 암호 개수 계산 (메모이제이션)
    dp[1]=P.length();
    for(int i=2; i<=T.length()-1; i++){
        dp[i]=(dp[i-1]*P.length())%MOD;
    }
    
    for(int i=1; i<=T.length()-1; i++){
        ans+=dp[i];
        ans%=MOD;
    }
    
    // 암호 길이와 같으면서 이전까지의 암호 개수 계산
    for(int i=0; i<T.length(); i++){
        int cur_idx=m[T.substr(i, 1)];
        if(i==T.length()-1){
            ans+=cur_idx;
        } else{
            ans+=dp[T.length()-1-i]*cur_idx;
        }
        ans%=MOD;
    }
    
    cout<<(ans+1)%MOD;
}