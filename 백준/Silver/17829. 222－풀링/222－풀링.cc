#include <bits/stdc++.h>
using namespace std;

int N, arr[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>arr[i][j];
            
    while(N>1){
        int temp[1025][1025];
        vector<int> v;
        for(int i=0; i<N/2; i++){
            for(int j=0; j<N/2; j++){
                v.push_back(arr[2*i][2*j]);
                v.push_back(arr[2*i+1][2*j]);
                v.push_back(arr[2*i][2*j+1]);
                v.push_back(arr[2*i+1][2*j+1]);
                
                sort(v.begin(), v.end());
                temp[i][j]=v[2];
                v.clear();
            }
        }
        
        for(int i=0; i<N/2; i++){
            for(int j=0; j<N/2; j++){
                arr[i][j]=temp[i][j];
            }
        }
        
        N/=2;
    }
    
    cout<<arr[0][0];
}