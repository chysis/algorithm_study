#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int Z;
    cin>>Z;
    while(Z--){
        int W, K;
        cin>>W>>K;
        cout<<max(W, K)*min(W, K)/2<<"\n";
    }
}