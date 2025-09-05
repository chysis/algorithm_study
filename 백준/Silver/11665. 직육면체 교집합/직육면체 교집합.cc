#include <iostream>
using namespace std;

int N, x1, y1, z1, x2, y2, z2, ax1=-1, ay1=-1, az1=-1, ax2=-1, ay2=-1, az2=-1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        if(ax1==-1){
            ax1=x1, ay1=y1, az1=z1, ax2=x2, ay2=y2, az2=z2;
        }else{
            ax1=max(ax1, x1), ay1=max(ay1, y1), az1=max(az1, z1);
            ax2=min(ax2, x2), ay2=min(ay2, y2), az2=min(az2, z2);
        }
        
        if(ax1>ax2 || ay1>ay2 || az1>az2){
            cout<<0;
            return 0;
        }
    }
    
    cout<<max((ax2-ax1)*(ay2-ay1)*(az2-az1), 0);
}