#include <bits/stdc++.h>
using namespace std;

// dp[i][j]: i를 루트로 하는 서브트리가 우수 마을일 때/아닐 때 서브트리 주민 수 총합
int N, A, B, arr[10001], dp[10001][2];
vector<int> adj[10001];

int solve(int cur, int parent, int wusu){
    int& temp=dp[cur][wusu];
    if(temp!=-1) return temp;
    
    temp=0;
    
    for(auto next: adj[cur]){
        if(next==parent) continue;
        if(wusu==1){
            temp+=solve(next, cur, 0);
        }else{
            temp+=max(solve(next, cur, 0), solve(next, cur, 1));
        }
    }
    
    if(wusu==1) temp+=arr[cur];
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        dp[i][0]=dp[i][1]=-1;
    }
    for(int i=1; i<=N; i++) cin>>arr[i];
    for(int i=0; i<N-1; i++){
        cin>>A>>B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    cout<<max(solve(1, 1, 0), solve(1, 1, 1));
}