#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, ans=0;
    cin>>N;
    for(int i=0; i<N; i++){
        int C, K;
        cin>>C>>K;
        ans+=(C*K);
    }
    
    cout<<ans;
}