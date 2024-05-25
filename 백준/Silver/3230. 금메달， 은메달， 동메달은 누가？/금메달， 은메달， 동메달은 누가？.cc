#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        int rank;
        cin>>rank;
        
        arr.insert(arr.begin()+rank-1, i);
    }
    
    for(int i=M-1; i>=0; i--){
        int rank;
        cin>>rank;
        
        ans.insert(ans.begin()+rank-1, arr[i]);
    }
    
    for(int i=0; i<3; i++){
        cout<<ans[i]<<"\n";
    }
}