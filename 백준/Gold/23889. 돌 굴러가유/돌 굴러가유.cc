#include <bits/stdc++.h>
using namespace std;

int N, M, K, sand[100001], rock[100001];
vector<pair<int, int>> v;
vector<int> ans;

bool comp(pair<int, int>& a, pair<int, int>& b){
    if(a.second!=b.second) return a.second>b.second;
    else return a.first<b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K;
    for(int i=1; i<=N; i++) cin>>sand[i];
    for(int i=0; i<K; i++) cin>>rock[i];
    rock[K]=N+1;
    
    for(int i=0; i<K; i++){
        int temp=0;
        for(int j=rock[i]; j<rock[i+1]; j++){
            temp+=sand[j];
        }
        v.push_back({rock[i], temp});
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<M; i++) ans.push_back(v[i].first);
    sort(ans.begin(), ans.end());
    for(auto a: ans) cout<<a<<"\n";
}