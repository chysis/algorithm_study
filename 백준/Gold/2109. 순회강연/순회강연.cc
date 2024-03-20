#include <iostream>
#include <queue>
using namespace std;

struct comp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.second!=b.second) return a.second>b.second;
        else return a.first<b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
priority_queue<int, vector<int>, greater<int>> selected;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int P, D;
        cin>>P>>D;
        pq.push({P, D});
    }
    
    int ans=0;
    int t=1;
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        
        if(cur.second>=t){
            selected.push(cur.first);
            t++;
        }else {
            if(selected.size()<=cur.second && selected.top()<cur.first){
                selected.pop();
                selected.push(cur.first);
            }
        }
    }
    
    while(!selected.empty()){
        ans+=selected.top();
        selected.pop();
    }
    cout<<ans;
}