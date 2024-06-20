#include <iostream>
#include <memory.h>
using namespace std;

int arr[10001];
bool visited[10001];

bool temp=true;
int cnt=0;

void dfs(int cur, int target){
    if(cur==target) return;
    int next=arr[cur];
    if(visited[next]) temp=false;
    else{
        cnt++;
        visited[next]=true;
        dfs(next, target);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        
        for(int i=1; i<=N; i++){
            cin>>arr[i];
        }
        
        dfs(1, N);
        if(!temp) cout<<0<<"\n";
        else cout<<cnt<<"\n";
        
        memset(visited, false, sizeof(visited));
        temp=true;
        cnt=0;
    }
}