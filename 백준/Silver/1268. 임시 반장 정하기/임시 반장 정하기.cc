#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int N, arr[1001][6];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }
    
    int maxIdx=0, maxVal=0;
    for(int i=0; i<N; i++){
        int temp=0;
        
        for(int j=0; j<N; j++){
            if(i==j) continue;
            for(int grade=0; grade<5; grade++){
                if(arr[i][grade]==arr[j][grade]){
                    temp++;
                    break;
                }
            }
        }
        
        if(maxVal<temp){
            maxIdx=i;
            maxVal=temp;
        }
    }
    
    cout<<maxIdx+1;
}