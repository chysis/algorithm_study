#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> arr[1000001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> v;

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
        v.push_back({arr[i].first, 1});
        v.push_back({arr[i].second, -1});
    }
    
    sort(v.begin(), v.end());
    
    int ans=0, temp=0;
    for(int i=0; i<v.size(); i++){
        if(v[i].second==1) {
            temp++;
            ans=max(ans, temp);
        }
        else temp--;
    }
    
    cout<<ans;
}