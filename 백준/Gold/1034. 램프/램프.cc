#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> v;
unordered_map<string, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, K;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    
    cin>>K;
    
    for(int i=0; i<v.size(); i++){
        int off=0;
        for(int j=0; j<M; j++){
            if(v[i][j]=='0') off++;
        }
        
        if(off<=K && abs(off-K)%2==0){
            if(um.find(v[i])!=um.end()) um[v[i]]++;
            else um[v[i]]=1;
        } 
    }
    
    int ans=0;
    for(auto a: um){
        ans=max(ans, a.second);
    }
    
    cout<<ans;
}