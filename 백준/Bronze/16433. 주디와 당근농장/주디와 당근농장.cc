#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, R, C;
    cin>>N>>R>>C;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if((abs(i-R)+abs(j-C))%2==1) cout<<'.';
            else cout<<"v";
        }
        cout<<"\n";
    }
}