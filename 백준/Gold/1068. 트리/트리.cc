#include <iostream>
using namespace std;

int N, target, parent[51];
bool cut[51];

bool isLeaf(int node){
    for(int i=0; i<N; i++){
        if(i==node || cut[i]) continue;
        if(parent[i]==node) return false;
    }
    return true;
}

void cutBranch(int node){
    cut[node]=true;
    
    for(int i=0; i<N; i++){
        if(parent[i]==node){
            cutBranch(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>parent[i];
    }
    cin>>target;
    
    cutBranch(target);
    
    int ans=0;
    for(int i=0; i<N; i++){
        if(cut[i]) continue;
        if(isLeaf(i)) ans++;
    }
    
    cout<<ans;
}