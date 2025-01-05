#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

multimap<int, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, K, N;
    char ch;
    cin>>T;
    while(T--){
        cin>>K;
        for(int i=0; i<K; i++){
            cin>>ch>>N;
            if(ch=='I') {
                mp.insert({N, 0});
            }
            else{
                if(mp.size()==0) continue;
                if(N==-1){
                    mp.erase(mp.find(mp.begin()->first));
                }
                else{
                    mp.erase(mp.find(mp.rbegin()->first));
                }
            }
        }
        if(mp.size()==0) cout<<"EMPTY\n";
        else cout<<mp.rbegin()->first<<" "<<mp.begin()->first<<"\n";
        
        mp.clear();
    }
}