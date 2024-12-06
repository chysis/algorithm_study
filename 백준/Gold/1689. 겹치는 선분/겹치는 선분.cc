#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> arr[1000001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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
    
    for(int i=0; i<N; i++){
        pq.push({arr[i].first, 1});
        pq.push({arr[i].second, -1});
    }
    
    int ans=0, temp=0;
    while(!pq.empty()){
        if(pq.top().second==1) {
            temp++;
            ans=max(ans, temp);
        }
        else temp--;
        
        pq.pop();
    }
    
    cout<<ans;
}