#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, M, N, x, y;
    cin>>T;
    
    while(T--){
        cin>>M>>N>>x>>y;
        if(x>y){
            swap(M, N);
            swap(x, y);
        }
        
        bool flag=false;
        for(int i=0; i<M; i++){
            if((N*i+y-x)%M==0){
                flag=true;
                cout<<N*i+y<<"\n";
                break;
            }
        }
        if(!flag) cout<<-1<<"\n";
    }
}