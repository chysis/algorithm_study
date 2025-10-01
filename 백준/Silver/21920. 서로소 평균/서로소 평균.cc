#include <bits/stdc++.h>
using namespace std;

int N, X, arr[500001];
double sum=0, cnt=0;

int gcd(int a, int b){
    return (a%b) ? gcd(b, a%b) : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout<<fixed;
    cout.precision(6);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    cin>>X;
    
    for(int i=0; i<N; i++){
        if(gcd(arr[i], X)==1) sum+=arr[i], cnt++;
    }
    cout<<sum/cnt;
}