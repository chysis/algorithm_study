#include <bits/stdc++.h>
using namespace std;

int P;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

string apply(string& s, int pos) {
    string t=s;
    int x=pos/3, y=pos%3;
    
    for(int k=0; k<5; k++) {
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx<0 || ny<0 || nx>=3 || ny>=3) continue;
        
        if(t[nx*3+ny]=='.') t[nx*3+ny] = '*';
        else if(t[nx*3+ny]=='*') t[nx*3+ny] = '.';
    }
    
    return t;
}

int bfs(const string& target) {
    string start(9, '.');
    if(start==target) return 0;

    unordered_set<string> visited;
    queue<pair<string, int>> q;
    visited.insert(start);
    q.push({start, 0});

    while(!q.empty()) {
        string cur=q.front().first;
        int dist=q.front().second;
        q.pop();

        for(int p=0; p<9; p++) {
            string next=apply(cur, p);
            if(next==cur) continue;
            if(visited.count(next)) continue;

            if(next==target) return dist+1;
            visited.insert(next);
            q.push({next, dist+1});
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>P;
    
    while(P--){
        string target(9, '.');
        for(int i=0; i<9; i++) cin>>target[i];
        cout<<bfs(target)<<"\n";
    }
}