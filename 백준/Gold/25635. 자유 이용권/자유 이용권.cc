#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    long long allSum=0;
    int max_v=-1;
    for(int i=0; i<N; i++){
        allSum+=arr[i];
        max_v=max(max_v, arr[i]);
    }
    
    if(max_v<=allSum-max_v){
        cout<<allSum;
    } else{
        cout<<(allSum-max_v)*2+1;
    }
}