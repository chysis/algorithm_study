#include <bits/stdc++.h>
using namespace std;

int N, ans=0;
pair<int, int> arr[51];
string A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A>>B;
        int sh=stoi(A.substr(0, 2));
        int sm=stoi(A.substr(2, 4));
        int eh=stoi(B.substr(0, 2));
        int em=stoi(B.substr(2, 4));
        arr[i]={sh*60+sm-10, eh*60+em+10};
    }
    
    sort(arr, arr+N);
    
    int prev=600;
    for(int i=0; i<N; i++){
        if(arr[i].first>=prev){
            ans=max(ans, arr[i].first-prev);
            prev=arr[i].second;
        }
        if(arr[i].second>=prev){
            prev=arr[i].second;
        }
    }
    ans=max(ans, 1320-prev);
    cout<<ans;
}