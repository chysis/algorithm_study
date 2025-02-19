#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, num, cost, dp[501];
pair<int, pair<int, vector<int>>> dat[501];
int indeg[501];
vector<int> adj[501], res;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>cost;
        vector<int> temp;
        while(true){
            cin>>num;
            if(num==-1) break;
            temp.push_back(num);
            adj[num].push_back(i);
            indeg[i]++;
        }
        dat[i]={i, {cost, temp}};
    }
    
    for(int i=1; i<=N; i++){
        if(indeg[i]==0) q.push(i);
    }
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        res.push_back(cur);
        
        for(auto& it: adj[cur]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    
    for(int i=0; i<N; i++){
        dp[res[i]]=dat[res[i]].second.first;
        
        for(auto& a: dat[res[i]].second.second){
            dp[res[i]]=max(dp[res[i]], dp[a]+dat[res[i]].second.first);
        }
    }
    
    for(int i=1; i<=N; i++){
        cout<<dp[i]<<"\n";
    }
}