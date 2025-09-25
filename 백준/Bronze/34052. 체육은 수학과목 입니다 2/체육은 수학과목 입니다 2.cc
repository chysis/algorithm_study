#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, sum=0;
    for(int i=0; i<4; i++){
        cin>>X;
        sum+=X;
    }
    cout<<(sum<=1500 ? "Yes" : "No");
}