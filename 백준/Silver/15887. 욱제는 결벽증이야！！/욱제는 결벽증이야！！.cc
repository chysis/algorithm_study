#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
vector<pair<int, int>> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    int cnt=0;
    for(int i=1; i<=N; i++){
        if(arr[i]==i) continue;
        
        int target;
        for(int j=i+1; j<=N; j++){
            if(arr[j]==i){
                target=j;
                break;
            }
        }
        cnt++;
        ans.push_back({i, target});
        reverse(arr+i, arr+target+1);
    }
    
    cout<<cnt<<"\n";
    for(auto a: ans){
        cout<<a.first<<" "<<a.second<<"\n";
    }
}