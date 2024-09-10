#include <iostream>
#include <algorithm>
using namespace std;

int a[101], b[101];

bool comp(int x, int y){
    return x>y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    
    sort(a, a+N);
    sort(b, b+N, comp);
    
    if(N%2==0){
        for(int i=N/2; i<N; i++){
            cout<<b[i]<<" "<<a[i]<<" ";
        }
    } else{
        cout<<a[N/2]<<" ";
        for(int i=N/2+1; i<N; i++){
            cout<<a[i]<<" "<<b[i]<<" ";
        }
    }
}