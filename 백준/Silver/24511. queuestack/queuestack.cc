#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, qs[100001], A[100001], C[100001];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    
    for(int i=0; i<N; i++){
        cin>>qs[i];
    }
    
    cin>>M;
    
    for(int i=0; i<M; i++){
        cin>>C[i];
    }
    
    for(int i=N-1; i>=0; i--){
        if(A[i]==0){
            q.push(qs[i]);
        }
    }
    
    for(int i=0; i<M; i++){
        int cur=-1;
        if(!q.empty()){
            cur=q.front();
            cout<<cur<<" ";
            q.pop();
            q.push(C[i]);
        } else{
            cout<<C[i]<<" ";
        }
    }
}