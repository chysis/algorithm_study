#include <bits/stdc++.h>
using namespace std;

int R, C, N, num, arr[1000001], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>R>>C>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        if(arr[num]<C) arr[num]++, ans++;
    }
    cout<<min(ans, R*C);
}