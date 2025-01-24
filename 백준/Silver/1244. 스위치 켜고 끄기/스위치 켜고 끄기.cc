#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
bool stat[101];

void boy(int num){
    for(int i=num; i<=N; i+=num){
        stat[i]=!stat[i];
    }
}

void girl(int num){
    int offset;
    for(int i=1; i<N; i++){
        if(num-i<1 || num+i>N || stat[num+i]!=stat[num-i]){
            offset=i-1;
            break;
        }
    }
    
    for(int i=num-offset; i<=num+offset; i++){
        stat[i]=!stat[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>stat[i];
    }
    
    cin>>M;
    for(int i=0; i<M; i++){
        int A, B;
        cin>>A>>B;
        if(A==1){
            boy(B);
        } else if(A==2){
            girl(B);
        }
    }
    
    for(int i=1; i<=N; i++){
        cout<<stat[i];
        if(i%20==0) cout<<"\n";
        else cout<<" ";
    }
}