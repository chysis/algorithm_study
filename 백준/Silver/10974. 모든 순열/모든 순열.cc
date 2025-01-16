#include <iostream>
using namespace std;

int N, ans[9];
bool used[9];

void solve(int cnt){
    if(cnt==N){
        for(int i=0; i<N; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(!used[i]){
            used[i]=true;
            ans[cnt]=i;
            solve(cnt+1);
            used[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    
    solve(0);
}