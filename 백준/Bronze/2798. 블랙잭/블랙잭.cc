#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int N, M, num, ans, x=300000;
    int arr[100];
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>num;
        arr[i]=num;
    }
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                num = arr[i]+arr[j]+arr[k];
                if(M-num<x && num<=M){
                    x=M-num;
                }
                
            }
        }
    }
    cout<<M-x<<'\n';
    return 0;
}