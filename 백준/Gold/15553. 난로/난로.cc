#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[100001];
bool group[100001];
vector<pair<int, int>> v;

bool comp(pair<int, int>& a, pair<int, int>& b){
    return a.first>b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        if(i>=1){
            v.push_back({arr[i]-arr[i-1], i-1});
        }
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<K-1; i++){
        group[v[i].second]=true;
    }
    
    int ans=0, temp=arr[0], idx=0;
    while(true){
        if(idx>=N) break;
        
        if(group[idx]) {
            ans+=arr[idx++]+1-temp;
            if(idx>=N) break;
            else temp=arr[idx];
        } else {
            idx++;
            if(idx>=N){
                ans+=arr[N-1]+1-temp;
                break;
            }
        }
    }
    
    cout<<ans;
}