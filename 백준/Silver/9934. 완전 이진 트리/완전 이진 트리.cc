#include <bits/stdc++.h>
using namespace std;

int K, arr[1025];
vector<int> ans[11];

void solve(int s, int e, int depth){
    if(e==s+2){
        ans[depth].push_back(arr[(s+e)/2]);
        ans[depth+1].push_back(arr[(s+e)/2-1]);
        ans[depth+1].push_back(arr[(s+e)/2+1]);
        return;
    }
    
    ans[depth].push_back(arr[(s+e)/2]);
    solve(s, (s+e)/2-1, depth+1);
    solve((s+e)/2+1, e, depth+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>K;
    for(int i=1; i<=pow(2, K)-1; i++) cin>>arr[i];
    solve(1, pow(2, K)-1, 0);
    for(int i=0; i<K; i++){
        for(auto a: ans[i]) cout<<a<<" ";
        cout<<"\n";
    }
}