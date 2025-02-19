#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int T, F, idx=0, parent[200001], cnt[200001];
unordered_map<string, int> um;

int find(int x){
    if(parent[x]==x) return x;
    
    return parent[x]=find(parent[x]);
}

int uni(int x, int y){
    int fx=find(x);
    int fy=find(y);

    if(fx==fy) return cnt[fx];
    if(fx>fy){
        parent[fy]=fx;
        return cnt[fx]+=cnt[fy];
    }
    parent[fx]=fy;
    return cnt[fy]+=cnt[fx];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>F;
        for(int i=1; i<=2*F; i++) {
            parent[i]=i;
            cnt[i]=1;
        }
        
        for(int i=0; i<F; i++){
            string A, B;
            cin>>A>>B;

            if(um.find(A)==um.end()){
                idx++;
                um.insert({A, idx});
            }
            
            if(um.find(B)==um.end()){
                idx++;
                um.insert({B, idx});
            }
            
            cout<<uni(um[A], um[B])<<"\n";
        }
        
        idx=0;
        um.clear();
    }
}