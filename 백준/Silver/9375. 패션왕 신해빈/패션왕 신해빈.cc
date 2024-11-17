#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        for(int i=0; i<N; i++){
            string name, cate;
            cin>>name>>cate;
            um[cate].push_back(name);
        }
        
        int ans=1;
        for(auto a: um){
            ans*=a.second.size()+1;
        }
        
        cout<<ans-1<<"\n";
        um.clear();
    }
}