#include <bits/stdc++.h>
using namespace std;

int N, num;
string it;
queue<pair<string, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>it>>num;
        q.push({it, num});
    }
    
    while(q.size()>1){
        string cur=q.front().first;
        int rep=q.front().second;
        q.pop();
        
        for(int i=0; i<rep-1; i++){
            auto a=q.front();
            q.pop();
            q.push(a);
        }
        q.pop();
    }
    
    cout<<q.front().first;
}