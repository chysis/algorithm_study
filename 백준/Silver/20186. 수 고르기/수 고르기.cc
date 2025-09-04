#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b){
    return a.first>b.first;
}

bool compIdx(pair<int, int>& a, pair<int, int>& b){
    return a.second<b.second;
}

int N, K, arr[5001];
vector<pair<int, int>> temp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
        temp.push_back({arr[i], i});
    }
    
    sort(temp.begin(), temp.end(), comp);
    sort(temp.begin(), temp.begin()+K, compIdx);
    
    int ans=0;
    for(int i=0; i<K; i++){
        ans+=temp[i].first-i;
    }
    cout<<ans;
}