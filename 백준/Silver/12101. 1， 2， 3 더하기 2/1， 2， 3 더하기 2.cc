#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<string> v;

void solve(int num, string s){
    if(num==0){
        v.push_back(s);
        return;
    }
    
    if(num>=1) solve(num-1, s+"1");
    if(num>=2) solve(num-2, s+"2");
    if(num>=3) solve(num-3, s+"3");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    solve(N, "");
    
    sort(v.begin(), v.end());
    
    if(v.size()<K) cout<<-1;
    else{
        for(int i=0; i<v[K-1].length()-1; i++){
            cout<<v[K-1][i]<<"+";
        }
        cout<<v[K-1][v[K-1].length()-1];
    }
}
