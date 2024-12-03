#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> arr[200001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int S, T;
        cin>>S>>T;
        arr[i]={S, T};
    }
    
    sort(arr, arr+N);
    pq.push(arr[0].second);
    
    for(int i=1; i<N; i++){
        if(arr[i].first<pq.top()) pq.push(arr[i].second);
        else {
            pq.pop();
            pq.push(arr[i].second);
        }
    }
    
    cout<<pq.size();
}