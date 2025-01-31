#include <iostream>
#include <algorithm>
using namespace std;

int K, info[7][3], cnt[5];
bool isLong[7];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>K;
    for(int i=0; i<6; i++){
        cin>>info[i][0]>>info[i][1];
        cnt[info[i][0]]++;
    }
    
    for(int i=1; i<=4; i++){
        if(cnt[i]==1){
            for(int j=0; j<6; j++){
                if(info[j][0]==i){
                    isLong[j]=true;
                }
            }
        }
    }
    
    for(int i=0; i<6; i++){
        if(isLong[i%6] && isLong[(i+1)%6]){
            cout<<(info[i%6][1]*info[(i+1)%6][1]-info[(i+3)%6][1]*info[(i+4)%6][1])*K;
            break;
        }
    }
}