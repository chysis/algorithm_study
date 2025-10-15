#include <bits/stdc++.h>
#define pss pair<string, string>
using namespace std;

int N;
string A, B;
pss arr[100001];

bool comp(pss a, pss b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second>b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    sort(arr, arr+N, comp);
    for(int i=0; i<N; i++){
        cout<<arr[i].first<<" "<<arr[i].second<<"\n";
    }
}