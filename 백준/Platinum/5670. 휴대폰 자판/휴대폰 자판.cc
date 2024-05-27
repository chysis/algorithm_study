#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Trie{
    bool isEnd;
    map<char, Trie*> child;
    
    void insert(string& str){
        Trie* now=this;
        
        for(int i=0; i<str.length(); i++){
            if(!now->child[str[i]]){
                now->child[str[i]]=new Trie();
            }
            now=now->child[str[i]];
            
            if(i==str.length()-1) now->isEnd=true;
        }
    }
    
    int solve(string& str){
        int cnt=1;
        Trie* now=child[str[0]];
        
        for(int i=1; i<str.length(); i++){
            if(now->isEnd || now->child.size()>1){
                cnt+=1;
            }
            now=now->child[str[i]];
        }
        return cnt;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cout<<fixed;
    cout.precision(2);
    
    int N;
    while(cin>>N){
        vector<string> v(N);
        for(int i=0; i<N; i++){
            cin>>v[i];
        }
        
        Trie* trie=new Trie();
        for(int i=0; i<N; i++){
            trie->insert(v[i]);
        }
        
        double sum=0;
        for(int i=0; i<N; i++){
            sum+=trie->solve(v[i]);
        }
        cout<<sum/N<<"\n";
        
        delete trie;
    }
}