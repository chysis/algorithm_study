#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> player;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        player[str]++;
    }
    
    for(int i=0; i<N-1; i++){
        string str;
        cin>>str;
        player[str]--;
        if(player[str]==0) player.erase(str);
    }
    
    for(auto a: player){
        cout<<a.first;
    }
}
