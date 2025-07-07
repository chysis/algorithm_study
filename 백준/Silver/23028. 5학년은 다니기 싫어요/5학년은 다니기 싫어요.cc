#include <bits/stdc++.h>
using namespace std;

int N, A, B, X, Y;
pair<int, int> arr[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>A>>B;
    for(int i=0; i<10; i++){
        cin>>X>>Y;
        arr[i]={X, Y};
    }
    
    if(A>=66 && B>=130){
        cout<<"Nice";
        return 0;
    }
    
    bool flag=false;
    for(int i=0; i<8-N; i++){
        A+=3*arr[i].first;
        int gyo=min(arr[i].second, 6-arr[i].first);
        B+=3*(arr[i].first+gyo);
        
        if(A>=66 && B>=130){
            flag=true;
            break;
        }
    }
    
    cout<<(flag ? "Nice" : "Nae ga wae");
}