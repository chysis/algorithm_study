#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[10001];
priority_queue<int, vector<int>, greater<int>> pq;

bool comp(int a, int b){
    return a>b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N, comp);
    
    int ans=0;
    for(int i=0; i<N; i++){
        if(pq.size()==M){
            ans=pq.top();
            while(!pq.empty()){
                if(pq.top()<=ans) pq.pop();
                else break;
            }
        }
        
        pq.push(ans+arr[i]);
    }
    
    while(!pq.empty()){
        ans=pq.top();
        pq.pop();
    }
    
    cout<<ans;
}