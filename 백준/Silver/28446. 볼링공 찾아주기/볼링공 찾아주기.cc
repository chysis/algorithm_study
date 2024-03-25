#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    cin>>M;
    while(M--){
        int opt;
        cin>>opt;
        if(opt==1){
            int x, w;
            cin>>x>>w;
            um[w]=x;
        } else if(opt==2){
            int w;
            cin>>w;
            cout<<um[w]<<"\n";
        }
    }
}