#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define pipii pair<int, pair<int, int>>
using namespace std;

bool comp(pipii& a, pipii& b){
    return a.second.first<b.second.first;
}

pipii arr[100001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
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
        if(!pq.empty() && pq.top()<=arr[i].second.first) {
            pq.pop();
            pq.push(arr[i].second.second);
        }
        else pq.push(arr[i].second.second);
    }
    
    cout<<pq.size();
}