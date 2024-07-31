#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> um;
vector<pair<string, int>> v;

bool comp(pair<string, int>& a, pair<string, int>& b){
    if(a.second!=b.second) return a.second>b.second;
    if(a.first.length()!=b.first.length()) return a.first.length()>b.first.length();
    return a.first<b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        if(str.length()<M) continue;
        if(um.find(str)!=um.end()){
            um[str]++;
        } else um.insert({str, 1});
    }
    
    v.resize(um.size());
    copy(um.begin(), um.end(), v.begin());
    
    sort(v.begin(), v.end(), comp);
    
    for(auto a: v){
        cout<<a.first<<"\n";
    }
}