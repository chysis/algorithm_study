#include <bits/stdc++.h>
using namespace std;

int C, R, K, arr[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>C>>R>>K;
    if(K>C*R) {
        cout<<0;
        return 0;
    }
    
    int num=1, cnt=0;
    
    while(true){
        if(num>C*R) break;
        
        // ->
        for(int i=cnt; i<R-cnt; i++){
            arr[cnt][i]=num++;
        }
        if(num>C*R) break;
        
        // ↓
        for(int i=cnt+1; i<C-cnt; i++){
            arr[i][R-cnt-1]=num++;
        }
        if(num>C*R) break;
        // <-
        for(int i=R-cnt-2; i>=cnt; i--){
            arr[C-cnt-1][i]=num++;
        }
        if(num>C*R) break;
        // ↑
        for(int i=C-cnt-2; i>=cnt+1; i--){
            arr[i][cnt]=num++;
        }
        
        cnt++;
    }
    
    for(int i=0; i<C; i++){
        for(int j=0; j<R; j++){
            if(arr[i][j]==K){
                cout<<i+1<<" "<<j+1;
                return 0;
            }
        }
    }
}