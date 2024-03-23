#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> uset; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int N, M;
        cin>>N;
        for(int i=0; i<N; i++){
            int num;
            cin>>num;
            uset.insert(num);
        }
        
        cin>>M;
        for(int i=0; i<M; i++){
            int num;
            cin>>num;
            if(uset.find(num)!=uset.end()){
                cout<<1<<"\n";
            } else{
                cout<<0<<"\n";
            }
        }
        
        uset.clear();
    }
}
