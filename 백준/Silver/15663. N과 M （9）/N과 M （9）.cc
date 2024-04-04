#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int sets[8];
int ans[8];
bool visited[8];

void solve(int cnt){
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    int prev=-1;
    for(int i=0; i<N; i++){
        if(!visited[i] && prev!=sets[i]){
            visited[i]=true;
            ans[cnt]=sets[i];
            prev=ans[cnt];
            solve(cnt+1);
            visited[i]=false;
        }
    }
}

int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>sets[i];
    }
    sort(sets, sets+N);
    solve(0);
}