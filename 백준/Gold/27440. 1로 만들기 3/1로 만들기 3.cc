#include <iostream>
#include <unordered_set>
#include <queue>

#define ll long long
using namespace std;

unordered_set<ll> visited;
queue<pair<ll, int>> q;

int main()
{
    ll N;
    cin>>N;
    
    q.push({N, 0});
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        
        if(cur.first==1){
            cout<<cur.second;
            return 0;
        }
        
        if(cur.first%3==0 && visited.find(cur.first/3)==visited.end()){
            q.push({cur.first/3, cur.second+1});
            visited.insert(cur.first/3);
        }
        
        if(cur.first%2==0 && visited.find(cur.first/2)==visited.end()){
            q.push({cur.first/2, cur.second+1});
            visited.insert(cur.first/2);
        }
        
        if(visited.find(cur.first-1)==visited.end()){
            q.push({cur.first-1, cur.second+1});
            visited.insert(cur.first-1);
        }
    }
}