#include <iostream>
using namespace std;

int DP[10001];

int main()
{
    int T, num;
    cin>>T;
    
    DP[0]=1;
    for(int i=1; i<=3; i++){
        for(int j=i; j<10001; j++){
            DP[j]+=DP[j-i];
        }
    }
    
    for(int i=0; i<T; i++){
        cin>>num;
        cout<<DP[num]<<"\n";
    }
}