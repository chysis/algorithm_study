#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> arr[100001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int S, E;
        cin>>S>>E;
        arr[i]={S, E};
    }
    
    sort(arr, arr+N);
    
    for(int i=0; i<N; i++){
        if(!pq.empty() && pq.top()<=arr[i].first) pq.pop();
        
        pq.push(arr[i].second);
    }
    
    cout<<pq.size();
}