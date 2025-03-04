#include <bits/stdc++.h>
using namespace std;

int N, K, sel[5];
string arr[11];
bool used[11];
set<string> s;

void solve(int cnt){
    if(cnt==K){
        string temp="";
        for(int i=0; i<K; i++){
            temp+=arr[sel[i]];
        }
        if(s.find(temp)==s.end()) s.insert(temp);
        return;
    }
    
    for(int i=0; i<N; i++){
        if(!used[i]){
            used[i]=true;
            sel[cnt]=i;
            solve(cnt+1);
            used[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    solve(0);
    cout<<s.size();
}