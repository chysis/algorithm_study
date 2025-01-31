#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, A, B;
    cin>>N>>A>>B;
    
    int cnt=1;
    while((A-1)/(int)pow(2, cnt)!=(B-1)/(int)pow(2, cnt)){
        cnt++;
    }
    cout<<cnt;
}