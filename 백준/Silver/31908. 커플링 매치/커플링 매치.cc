#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string p, s;
        cin>>p>>s;
        if(s=="-") continue;
        
        um[s].push_back(p);
    }
    
    int cnt=0;
    vector<pair<string, string>> ans;
    
    for(auto a: um){
        if(a.second.size()==2){
            for(int i=0; i<a.second.size(); i++){
                for(int j=i+1; j<a.second.size(); j++){
                    ans.push_back({a.second[i], a.second[j]});
                    cnt++;
                }
            }
        }
    }
    
    cout<<cnt<<"\n";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}