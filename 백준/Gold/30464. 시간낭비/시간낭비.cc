#include <iostream>
#include <algorithm>
using namespace std;

int N, map[200001], dp[200001];

void print(){
    for(int i=1; i<=N; i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>map[i];
    }
    
    for(int i=1; i<N; i++){
        int next=i+map[i];
        if(i>1 && dp[i]==0) continue; // 접근할 수 없는 곳
        if(map[i]==0) continue;
        if(next>N) continue;
        dp[next]=max(dp[next], dp[i]+1);
    }
    
    // print();
    
    // 방향 바꿔서 돌아갈 때
    for(int i=N-1; i>1; i--){
        int next=i-map[i];
        if(next<1) continue;
        if(dp[i]==0 || map[i]==0) continue;
        
        dp[next]=max(dp[next], dp[i]+1);
    }
    
    // print();
    
    for(int i=1; i<N; i++){
        int next=i+map[i];
        if(next>N) continue;
        if(dp[i]==0 || map[i]==0) continue;
        
        dp[next]=max(dp[next], dp[i]+1);
    }
    
    // print();
    
    cout<<(dp[N]==0 ? -1 : dp[N]);
}