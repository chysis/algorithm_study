#include <iostream>
using namespace std;

int N, tar=1, arr[8], temp[8], ans[8];
bool done=false;

void solve(int cnt){
    if(cnt==N){
        if(done) return;
        int mul=1;
        for(int i=0; i<N; i++){
            mul*=temp[i];
        }
        
        if(mul>tar){
            done=true;
            for(int i=0; i<N; i++){
                ans[i]=temp[i];
            }
        }
        
        return;
    }
    
    for(int i=1; i<=9; i++){
        temp[cnt]=i;
        solve(cnt+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        tar*=arr[i];
    }
    
    solve(0);
    
    if(done){
        for(int i=0; i<N; i++){
            cout<<ans[i]<<" ";
        }
    } else{
        cout<<-1;
    }
}