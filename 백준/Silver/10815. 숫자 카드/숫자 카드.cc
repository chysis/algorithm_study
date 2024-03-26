#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> us;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        us.insert(num);
    }
    
    int M;
    cin>>M;
    for(int i=0; i<M; i++){
        int num;
        cin>>num;
        if(us.find(num)!=us.end()){
            cout<<1<<" ";
        } else cout<<0<<" ";
    }
}