#include <bits/stdc++.h>
using namespace std;

int N, Te, Tx;
vector<pair<int, int>> mm, psum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>Te>>Tx;
        mm.push_back({Te, 1});
        mm.push_back({Tx, -1});
    }
    
    sort(mm.begin(), mm.end());
    
    int idx=0, prev;
    while(idx<mm.size()){
        prev=mm[idx].first;
        int temp=0;
        while(true){
            temp+=mm[idx].second;
            idx++;
            
            if(mm[idx].first!=prev) break;
        }
        
        if(psum.size()==0) psum.push_back({prev, temp});
        else psum.push_back({prev, psum.back().second+temp});
    }
    
    int maxVal=-1;
    for(auto a: psum){
        maxVal=max(maxVal, a.second);
    }
    
    int ansX=INT_MAX, ansY=-1;
    for(auto a: psum){
        if(a.second==maxVal){
            ansX=min(ansX, a.first);
        } else{
            if(ansX==INT_MAX) continue;
            else {
                ansY=max(ansY, a.first);
                break;
            }
        }
    }
    
    cout<<maxVal<<"\n"<<ansX<<" "<<ansY;
}