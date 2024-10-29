#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int h, m;
        char c;
        cin>>h>>c>>m;
        arr[i]=h*60+m;
    }
    
    sort(arr, arr+N);
    
    int ans=0, temp=1;
    for(int i=1; i<N; i++){
        if(arr[i]-arr[i-1]<=10){
            temp++;
            if(temp==3){
                ans++;
                temp=1;
            }
        } else{
            ans++;
            temp=1;
        }
    }
    
    cout<<ans;
}