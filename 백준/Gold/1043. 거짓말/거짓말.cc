#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, M, T;
set<int> whoKnowsTruth;

bool adj[51][51];
bool found[51];
vector<int> party[51];

void dfs(int start){
    found[start]=true;
    
    for(int i=1; i<=N; i++){
        if(start==i) continue;
        if(adj[start][i] && !found[i]) dfs(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M>>T;
    for(int i=0; i<T; i++){
        int num;
        cin>>num;
        whoKnowsTruth.insert(num);
    }
    
    for(int i=0; i<M; i++){
        int num;
        cin>>num;
        for(int j=0; j<num; j++){
            int person;
            cin>>person;
            
            party[i].push_back(person);
        }
        
        for(int j=0; j<party[i].size(); j++){
            for(int k=0; k<party[i].size(); k++){
                if(j==k) continue;
                adj[party[i][j]][party[i][k]]=true;
                adj[party[i][k]][party[i][j]]=true;
            }
        }
    }
    
    if(T==0){
        cout<<M;
        return 0;
    }
    
    for(auto a: whoKnowsTruth){
        dfs(a);
    }
    
    int ans=M;
    for(int i=0; i<M; i++){
        bool flag=false;
        for(auto a: party[i]){
            if(found[a]){
                flag=true;
                break;
            }
        }
        if(flag) ans--;
    }
    cout<<ans;
}