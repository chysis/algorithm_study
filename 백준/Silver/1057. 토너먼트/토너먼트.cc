#include <iostream>
#include <cmath>
using namespace std;

int N, A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>A>>B;
    
    int cnt=1;
    while(true){
        if((A-1)/(int)pow(2, cnt)==(B-1)/(int)pow(2, cnt)) break;
        cnt++;
    }
    
    cout<<cnt;
}