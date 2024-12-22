#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100001];
int date[120001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int y1, m1, y2, m2;
        char c;
        cin>>y1>>c>>m1>>y2>>c>>m2;
        arr[i]={y1*12+m1, y2*12+m2};
    }
    
    sort(arr, arr+N);
    
    for(int i=0; i<N; i++){
        date[arr[i].first]++;
        date[arr[i].second+1]--;
    }
    
    int cur=0, mx=-1, ans=-1;
    for(int i=0; i<120001; i++){
        cur+=date[i];
        if(cur>mx){
            mx=cur;
            ans=i;
        }
    }
    
    if(ans%12==0){
        cout<<ans/12-1<<"-"<<12;
    }else{
        cout<<ans/12<<"-";
        if(ans%12<10){
            cout<<0<<ans%12;
        } else cout<<ans%12;
    }
}