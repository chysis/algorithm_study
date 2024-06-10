#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int ans[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        q.push({i, num});
    }
    
    int t=0;
    while(!q.empty()){
        t++;
        auto cur=q.front();
        q.pop();
        if(cur.second-1==0){
            ans[cur.first]=t;
        } else{
            q.push({cur.first, cur.second-1});
        }
    }
    
    for(int i=0; i<N; i++){
        cout<<ans[i]<<" ";
    }
}