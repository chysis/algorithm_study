#include <bits/stdc++.h>
using namespace std;

int N, P, W, L, G, score=0;
string name, res, player;
unordered_map<string, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>P>>W>>L>>G;
    for(int i=0; i<P; i++){
        cin>>name>>res;
        if(res=="W") um.insert({name, 1});
        else um.insert({name, 0});
    }
    
    for(int i=0; i<N; i++){
        cin>>player;
        if(um.find(player)==um.end()) score=max(0, score-L);
        else if(um[player]==1) score+=W;
        else score=max(0, score-L);
        
        if(score>=G){
            cout<<"I AM NOT IRONMAN!!";
            return 0;
        }
    }
    
    cout<<"I AM IRONMAN!!";
}