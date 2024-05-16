#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[1001];

bool comp(string a, string b){
    return a+b<b+a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+N, comp);
    
    string ans="";
    for(int i=N-1; i>=0; i--){
        ans+=arr[i];
    }
    
    while(true){
        if(ans.length()==1 || ans[0]!='0') break;
        ans=ans.substr(1);
    }
    
    cout<<ans;
}