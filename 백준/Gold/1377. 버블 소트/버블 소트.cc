#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        arr.push_back({num, i});
    }
    
    sort(arr.begin(), arr.end());
    
    int ans=-1;
    for(int i=0; i<N; i++){
        ans=max(ans, arr[i].second-i);
    }
    cout<<ans+1;
}