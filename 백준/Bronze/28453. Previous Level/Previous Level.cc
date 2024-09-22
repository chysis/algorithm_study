#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>M;
        if(M==300) cout<<1<<" ";
        else if(M>=275) cout<<2<<" ";
        else if(M>=250) cout<<3<<" ";
        else cout<<4<<" ";
    }
}