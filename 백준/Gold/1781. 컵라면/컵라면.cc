#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct comp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
priority_queue<int, vector<int>, greater<int>> selected;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int d, r;
        cin>>d>>r;
        pq.push({d, r});
    }
    
    long long ans=0;
    int t=1;
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        
        if(t<=cur.first){
            selected.push(cur.second);
            t++;
        } else{
            if(cur.first==selected.size() && cur.second>selected.top()){
                selected.pop();
                selected.push(cur.second);
            }
        }
    }
    
    while(!selected.empty()){
        ans+=selected.top();
        selected.pop();
    }
    
    cout<<ans;
}