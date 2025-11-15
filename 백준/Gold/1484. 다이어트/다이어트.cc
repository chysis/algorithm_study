#include <bits/stdc++.h>
using namespace std;

int G;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>G;
    int s=1, e=2;
    while(s<e){
        int res=e*e-s*s;
        if(res==G){
            ans.push_back(e);
            e++;
        }
        else if(res>G) s++;
        else e++;
    }
    
    if(ans.size()==0) cout<<"-1";
    else{
        for(auto a: ans) cout<<a<<"\n";
    }
}