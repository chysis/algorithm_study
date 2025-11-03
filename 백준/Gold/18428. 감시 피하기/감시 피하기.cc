#include <bits/stdc++.h>
using namespace std;

int N, sel[3];
vector<pair<int, int>> T;
char arr[7][7];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool flag=false, visited[7][7];

bool isValid(){
    // 세팅
    char temp[7][7];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j]=arr[i][j];
        }
    }
    
    for(int i=0; i<3; i++) temp[sel[i]/N][sel[i]%N]='O';
    
    // 감시
    for(auto teacher: T){
        int x=teacher.first, y=teacher.second;
        
        for(int i=x; i>=0; i--){
            if(temp[i][y]=='S') return false;
            else if(temp[i][y]=='O') break;
        }
        for(int i=x; i<N; i++){
            if(temp[i][y]=='S') return false;
            else if(temp[i][y]=='O') break;
        }
        for(int i=y; i>=0; i--){
            if(temp[x][i]=='S') return false;
            else if(temp[x][i]=='O') break;
        }
        for(int i=y; i<N; i++){
            if(temp[x][i]=='S') return false;
            else if(temp[x][i]=='O') break;
        }
    }
    
    return true;
}

void solve(int cnt, int prev){
    if(cnt==3){
        if(isValid()) flag=true;
        return;
    }
    
    if(flag) return;
    
    for(int i=prev+1; i<N*N; i++){
        int x=i/N, y=i%N;
        if(arr[x][y]!='X') continue;
        
        if(!visited[x][y]){
            visited[x][y]=true;
            sel[cnt]=i;
            solve(cnt+1, i);
            visited[x][y]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='T') T.push_back({i, j});
        }
    }
    
    solve(0, -1);
    if(flag) cout<<"YES";
    else cout<<"NO";
}