#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int hut, dis, num;
vector<vector<int>> v(20001);
int visited[20001];
queue<int> q;

void bfs(){
    while(!q.empty()){
        int next=q.front();
        q.pop();
        for(int i=0; i<v[next].size(); i++){
            if(!visited[v[next][i]]){
                q.push(v[next][i]);
                visited[v[next][i]]=visited[next]+1;
            }
        }
    }
}

int main()
{
    int N, M, A, B;
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    for(int i=1; i<=N; i++){
        sort(v[i].begin(), v[i].end());
    }
    q.push(1);
    visited[1]=1;
    bfs();
    for(int i=2; i<=N; i++){
        if(visited[i]>dis){
            hut=i;
            dis=visited[i];
            num=1;
        }
        else if(visited[i]==dis){
            num++;
        }
    }
    cout<<hut<<" "<<dis-1<<" "<<num;
}