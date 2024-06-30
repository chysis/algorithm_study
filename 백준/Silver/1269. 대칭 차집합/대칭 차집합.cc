#include <iostream>
#include <string>
#include <set>
using namespace std;

int arr1[200001];
int arr2[200001];
set<int> s1, s2;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr1[i];
        s1.insert(arr1[i]);
    }
    
    for(int i=0; i<M; i++){
        cin>>arr2[i];
        s2.insert(arr2[i]);
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        if(s2.find(arr1[i])==s2.end()) ans++;
    }
    
    for(int i=0; i<M; i++){
        if(s1.find(arr2[i])==s1.end()) ans++;
    }
    
    cout<<ans;
}