#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Trie{
    bool isEnd=false;
    map<char, Trie*> child;
    
    void insert(string& str){
        Trie* now=this;
        
        for(int i=0; i<str.length(); i++){
            char cur=str[i];
            
            if(!now->child[cur]){
                now->child[cur]=new Trie();
            }
            now=now->child[cur];
            
            if(i==str.length()-1){
                now->isEnd=true;
            }
        }
    }
};

Trie* color=new Trie();
Trie* teamName=new Trie();

bool colorCheck[2001];
bool nameCheck[2001];

bool solve(string& target){
    memset(colorCheck, false, sizeof(colorCheck));
    memset(nameCheck, false, sizeof(nameCheck));
    
    Trie* tempColor=color;
    
    for(int i=0; i<target.length(); i++){
        char cur=target[i];
        
        bool flag=false;

        for(auto a: tempColor->child){
            if(a.first==cur){
                flag=true;
                tempColor=a.second;
                break;
            }
        }
        
        if(!flag){
            break;
        }
        
        if(tempColor->isEnd){
            colorCheck[i]=true;
        }
    }
    
    Trie* tempTeamName=teamName;
    
    for(int i=target.length()-1; i>=0; i--){
        char cur=target[i];
        
        bool flag=false;

        for(auto a: tempTeamName->child){
            if(a.first==cur){
                flag=true;
                tempTeamName=a.second;
                break;
            }
        }
        
        if(!flag){
            break;
        }
        
        if(tempTeamName->isEnd){
            nameCheck[i]=true;
        }
    }
    
    for(int i=0; i<target.length()-1; i++){
        if(colorCheck[i] && nameCheck[i+1]){
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int C, N;
    cin>>C>>N;
    for(int i=0; i<C; i++){
        string str;
        cin>>str;
        color->insert(str);
    }
    
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        reverse(str.begin(), str.end());
        teamName->insert(str);
    }
    
    int Q;
    cin>>Q;
    for(int i=0; i<Q; i++){
        string str;
        cin>>str;
        if(solve(str)){
            cout<<"Yes\n";
        } else{
            cout<<"No\n";
        }
    }
    
    delete color;
    delete teamName;
    
    return 0;
}