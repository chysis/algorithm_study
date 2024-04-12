#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int N, M, K, res=-INF;
int arr[11][11];
int ans[5];
bool visited[10*10+1];

int result(){
    int temp=0;
    for(int i=0; i<K; i++){
        temp+=arr[ans[i]/M][ans[i]%M];
    }
    
    return temp;
}

bool isPromising(){
    for(int i=0; i<K; i++){
        int curX=ans[i]/M;
        int curY=ans[i]%M;
        
        for(int j=i+1; j<K; j++){
            int tarX=ans[j]/M;
            int tarY=ans[j]%M;
            if(abs(tarX-curX)+abs(tarY-curY)==1) return false;
        }
    }
    
    return true;
}

void solve(int cnt, int idx){
    if(cnt==K){
        if(isPromising()){
            res=max(res, result());
        }
        return;
    }
    
    for(int i=idx; i<N*M; i++){
        if(!visited[i]){
            visited[i]=true;
            ans[cnt]=i;
            solve(cnt+1, i);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    solve(0, 0);
    cout<<res;
}