#include <bits/stdc++.h>
using namespace std;

int N;
char arr[555555];

void solve(int idx, int N){
    if(N==1){
        arr[idx]='-', arr[idx+1]=' ', arr[idx+2]='-';
        return;
    }
    
    solve(idx, N-1);
    solve(idx+2*pow(3, N-1), N-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin>>N){
        for(int i=0; i<pow(3, N); i++) arr[i]=' ';
        if(N==0) {
            cout<<"-\n";
            continue;
        }
        
        solve(0, N);
        for(int i=0; i<pow(3, N); i++) cout<<arr[i];
        cout<<"\n";
    }
}