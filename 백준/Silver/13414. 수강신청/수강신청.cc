#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> um;

bool comp(pair<string, int>& a, pair<string, int>& b){
    return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int K, L;
    cin>>K>>L;
    for(int i=0; i<L; i++){
        string str;
        cin>>str;
        um[str]=i;
        
    }
    
    vector<pair<string, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), comp);
    
    int cnt=0;
    for(auto a: v){
        cout<<a.first<<"\n";
        cnt++;
        if(cnt==K) break;
    }
}