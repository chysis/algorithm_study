#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ans;
vector<bool> visited;
bool isDone=false;

// 방문 처리 인덱스 확인용 tickets
void dfs(string cur, int cnt, vector<vector<string>>& tickets, vector<string>& path){
    if(isDone) return;
    
    if(cnt==tickets.size()){
        ans=path;
        isDone=true;
        return;
    }
    
    for(int i=0; i<tickets.size(); i++){
        if(!visited[i] && tickets[i][0]==cur){
            visited[i]=true;
            path.push_back(tickets[i][1]);
            
            dfs(tickets[i][1], cnt+1, tickets, path);
            
            path.pop_back();
            visited[i]=false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // 오름차순 정렬
    vector<vector<string>> t=tickets;
    sort(t.begin(), t.end());
    
    // visited 배열의 크기는 tickets에 따라 동적으로 결정
    visited.assign(tickets.size(), false);
    
    // dfs
    // 같은 공항에 다시 방문할 수 있음
    // ticket별로 방문 처리 -> tickets의 인덱스로 생각
    vector<string> path;
    path.push_back("ICN");
    
    dfs("ICN", 0, t, path);
    
    return ans;
}