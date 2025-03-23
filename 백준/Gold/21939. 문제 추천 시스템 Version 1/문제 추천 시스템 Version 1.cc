#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

set<pair<int, int>> problems;
map<int, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N;
    for(int i=0; i<N; i++){
        int P, L;
        cin>>P>>L;
        problems.insert({L, P});
        m[P]=L;
    }
    
    cin>>M;
    for(int i=0; i<M; i++){
        string str;
        cin>>str;
        if(str=="recommend"){
            int x;
            cin>>x;
            if(x==1){
                cout<<problems.rbegin()->second<<"\n";
            }
            else if(x==-1){
                cout<<problems.begin()->second<<"\n";
            }
        }
        else if(str=="add"){
            int P, L;
            cin>>P>>L;
            problems.insert({L, P});
            m[P]=L;
        }
        else if(str=="solved"){
            int P;
            cin>>P;
            int L=m[P];
            auto a=problems.find({L, P});
            problems.erase(a);
        }
    }
}