#include <iostream>
using namespace std;

int N, M, parent[1000001];

int find(int x){
    if(parent[x]==x) return x;
    
    return parent[x]=find(parent[x]);
}

void uni(int x, int y){
    int px=find(x);
    int py=find(y);
    
    if(px!=py) parent[px]=py;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=1; i<=N; i++){
        parent[i]=i;
    }
    
    for(int i=0; i<M; i++){
        int opt, a, b;
        cin>>opt>>a>>b;
        if(opt==0){
            uni(a, b);
        } else if(opt==1){
            if(a==b) {
                cout<<"YES\n";
                continue;
            }
            
            int pa=find(a);
            int pb=find(b);
            if(pa==pb) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}