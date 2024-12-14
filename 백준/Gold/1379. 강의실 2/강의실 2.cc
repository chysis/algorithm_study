#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define pipii pair<int, pair<int, int>>
using namespace std;

bool comp(pipii& a, pipii& b){
    return a.second.first<b.second.first;
}

pipii arr[100001];
int cnt=0, ans[100001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num, s, e;
        cin>>num>>s>>e;
        arr[i]={num, {s, e}};
    }
    
    sort(arr, arr+N, comp);
    
    for(int i=0; i<N; i++){
        if(!pq.empty() && pq.top().first<=arr[i].second.first){
            int num=pq.top().second;
            pq.pop();
            pq.push({arr[i].second.second, num});
            ans[arr[i].first]=num;
        }else{
            ans[arr[i].first]=++cnt;
            pq.push({arr[i].second.second, cnt});
        }
    }
    
    cout<<cnt<<"\n";
    for(int i=1; i<=N; i++){
        cout<<ans[i]<<"\n";
    }
}