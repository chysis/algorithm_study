#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct comp{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return min(a.second, 100-a.first)<min(b.second, 100-b.first);
    }
};

int N, M, ans=0;
pair<int, int> arr[200001];
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int num; cin>>num;
        arr[i].first=num;
        ans+=num;
    }
    
    for(int i=0; i<M; i++){
        int num; cin>>num;
        arr[i].second=num;
    }
    
    for(int i=0; i<M; i++){
        pq.push(arr[i]);
    }
    
    int t=24*N;
    while(t>0 && !pq.empty()){
        auto cur=pq.top();
        pq.pop();
        
        if(cur.first==100) continue;
        
        int needTime=min(t, (100-cur.first>=cur.second) ? 
            (100-cur.first)/cur.second : 1);
        int addScore=(100-cur.first>=cur.second) ?
            needTime * cur.second : 100-cur.first;
            
        cur.first+=addScore;
        t-=needTime;
        ans+=addScore;
        
        pq.push(cur);
    }
    
    cout<<ans;
}