#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> temp;

struct Trie{
    map<string, Trie*> children;
    
    void insert(vector<string>& v){
        Trie* now=this;
        for(int i=0; i<v.size(); i++){
            if(!now->children[v[i]]){
                now->children[v[i]] = new Trie;
            }
            now=now->children[v[i]];
        }
    }
};

void dfs(Trie* trie, int depth){
    for(auto it=trie->children.begin(); it!=trie->children.end(); it++){
        for(int i=0; i<depth; i++){
            cout<<"--";
        }
        cout<<it->first<<"\n";
        dfs(it->second, depth+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Trie* trie = new Trie;
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int K;
        cin>>K;
        for(int j=0; j<K; j++){
            string str;
            cin>>str;
            temp.push_back(str);
        }
        
        trie->insert(temp);
        temp.clear();
    }
    
    dfs(trie, 0);
    delete trie;
}