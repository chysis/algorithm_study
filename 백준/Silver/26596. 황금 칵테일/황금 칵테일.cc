#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<string, double> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M;
    cin>>M;
    for(int i=0; i<M; i++){
        string s;
        int x;
        cin>>s>>x;
        if(um.find(s)==um.end()){
            um.insert({s, x});
        } else{
            um[s]+=x;
        }
    }
    
    for(auto e: um){
        for(auto e2: um){
            if(e.first==e2.first) continue;
            
            if(floor(e.second*1.618)==(int)(e2.second)){
                cout<<"Delicious!";
                return 0;
            }
        }
    }
    
    cout<<"Not Delicious...";
}