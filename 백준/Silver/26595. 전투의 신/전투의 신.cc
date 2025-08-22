#include <bits/stdc++.h>
using namespace std;

long long N, A, PA, B, PB, maxVal=0, x, y;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>A>>PA>>B>>PB;
    for(int i=0; ; i++){
        if(PA*i>N) break;
        int yCnt=(N-PA*i)/PB;
        long long temp=A*i+B*yCnt;
        if(maxVal<temp){
            maxVal=temp;
            x=i, y=yCnt;
        }
    }
    cout<<x<<" "<<y;
}