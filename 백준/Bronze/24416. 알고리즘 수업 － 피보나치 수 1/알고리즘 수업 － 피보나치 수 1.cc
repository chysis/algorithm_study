#include <iostream>
using namespace std;

int N, ans1=0, ans2=0, f[41];

int fib(int n){
    if(n==1 || n==2) {
        ans1++;
        return 1;
    }
    else return fib(n-1)+fib(n-2);
}

int fibonacci(int n){
    f[1]=f[2]=1;
    for(int i=3; i<=n; i++){
        f[i]=f[i-1]+f[i-2];
        ans2++;
    }
    return f[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    fib(N);
    fibonacci(N);
    cout<<ans1<<" "<<ans2;
}