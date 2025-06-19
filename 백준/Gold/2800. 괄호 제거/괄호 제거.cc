#include <bits/stdc++.h>
using namespace std;

int N, sel[11];
string S;
stack<int> st;
vector<pair<int, int>> v;
vector<string> res;
bool visited[11];

void solve(int target, int cnt, int prev){
    if(cnt==target){
        string temp=S;
        vector<int> idx;
        for(int i=0; i<target; i++){
            idx.push_back(v[sel[i]].first);
            idx.push_back(v[sel[i]].second);
        }
        
        sort(idx.begin(), idx.end());
        for(int i=idx.size()-1; i>=0; i--){
            temp.erase(idx[i], 1);
        }
        
        res.push_back(temp);
        return;
    }
    
    for(int i=prev; i<N; i++){
        if(!visited[i]){
            visited[i]=true;;
            sel[cnt]=i;
            solve(target, cnt+1, i);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    for(int i=0; i<S.length(); i++){
        if(S[i]=='(') st.push(i);
        else if(S[i]==')'){
            v.push_back({st.top(), i});
            st.pop();
        }
    }
    
    N=v.size();
    for(int i=1; i<=N; i++){
        solve(i, 0, 0);
    }
    
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for(auto a: res) cout<<a<<"\n";
}