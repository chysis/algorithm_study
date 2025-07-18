#include <bits/stdc++.h>
using namespace std;

int N, T, X, Y;
pair<int, int> arr[50005];
queue<pair<pair<int, int>, int>> q;
bool visited[50005];

bool comp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int solve(){
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        
        if(y==T) return cnt;
        
        auto lo=lower_bound(arr, arr+N+1, pair<int, int>(x-2, y-2), comp)-arr;
        auto hi=upper_bound(arr, arr+N+1, pair<int, int>(x+2, y+2), comp)-arr;
        for(int i=lo; i<hi; i++){
            if(abs(arr[i].second-y)>2) continue;
            if(visited[i]) continue;
            
            q.push({{arr[i].first, arr[i].second}, cnt+1});
            visited[i]=true;
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>T;
    arr[0]={0, 0};
    for(int i=1; i<=N; i++){
        cin>>X>>Y;
        arr[i]={X, Y};
    }
    
    sort(arr, arr+N+1, comp);
    
    visited[0]=true;
    q.push({{0, 0}, 0});
    cout<<solve();
}