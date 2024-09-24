#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    
    cout<<fixed;
    cout.precision(1);
    
    for(int i=0; i<N; i++){
        double A, B;
        cin>>A>>B;
        if(A>B) cout<<A-B<<"\n";
        else cout<<B-A<<"\n";
    }
}