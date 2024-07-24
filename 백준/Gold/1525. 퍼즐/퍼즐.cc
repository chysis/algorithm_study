#include <iostream>
#include <set>
#include <string>
#include <queue>
using namespace std;

int map[3][3];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
set<string> s;
queue<pair<string, int>> q;
string target="123456780";

string mapToStr(){
    string str="";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            str+=map[i][j]+'0';
        }
    }
    
    return str;
}

int bfs(){
    while(!q.empty()){
        string cur=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(cur==target) return cnt;
        
        int idx=cur.find("0");
        int x=idx/3;
        int y=idx%3;
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            string ns=cur;
            
            if(nx<0 || ny<0 || nx>2 || ny>2) continue;
            int nidx=nx*3+ny;
            
            char temp=ns[idx];
            ns[idx]=ns[nidx];
            ns[nidx]=temp;
            
            if(s.find(ns)!=s.end()) continue;
            
            s.insert(ns);
            q.push({ns, cnt+1});
        }
    }
    
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>map[i][j];
        }
    }
    
    s.insert(mapToStr());
    q.push({mapToStr(), 0});
    cout<<bfs();
}