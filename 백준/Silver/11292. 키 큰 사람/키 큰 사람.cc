#include <bits/stdc++.h>
using namespace std;

int N;
string S;
double H;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin>>N){
        if(N==0) break;
        
        vector<string> ans;
        double m=0.0;
        for(int i=0; i<N; i++){
            cin>>S>>H;
            if(H>m){
                ans.clear();
                ans.push_back(S);
                m=H;
            } else if(H==m) ans.push_back(S);
        }
        
        for(auto a: ans) cout<<a<<" ";
        cout<<"\n";
    }
}