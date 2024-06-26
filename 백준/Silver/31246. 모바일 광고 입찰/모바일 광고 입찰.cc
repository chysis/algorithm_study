#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    
    int cnt=0;
    for(int i=0; i<N; i++){
        int A, B;
        cin>>A>>B;
        if(A>=B){
            cnt++;
            continue;
        }
        
        arr.push_back(B-A);
    }
    
    if(cnt>=K){
        cout<<0;
        return 0;
    }
    
    sort(arr.begin(), arr.end());
    
    cout<<arr[K-cnt-1];
}