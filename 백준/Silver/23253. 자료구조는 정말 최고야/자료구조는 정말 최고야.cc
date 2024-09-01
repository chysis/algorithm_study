#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K;
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>K;
        int arr[200001];
        for(int j=0; j<K; j++){
            cin>>arr[j];
        }
        
        for(int j=0; j<K-1; j++){
            if(arr[j]<arr[j+1]){
                cout<<"No";
                return 0;
            }
        }
    }
    
    cout<<"Yes";
}