#include <iostream>
using namespace std;

int N, num, A[1000001], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        A[num]++;
    }
    
    for(int i=0; i<N; i++){
        cin>>num;
        if(A[num]>0) A[num]--;
        else ans++;
    }

    cout<<ans;
}