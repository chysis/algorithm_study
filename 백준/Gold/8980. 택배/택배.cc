#include <iostream>
#include <tuple>
#include <algorithm>

#define tiii tuple<int, int, int>
using namespace std;

tiii arr[10001];
int maeul[2001];

bool comp(tiii& a, tiii& b){
    if(get<1>(a)!=get<1>(b)){
        return (get<1>)(a)<(get<1>)(b);
    } else{
        return (get<0>)(a)<(get<0>)(b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, C, M;
    cin>>N>>C>>M;
    for(int i=1; i<=M; i++){
        int A, B, box;
        cin>>A>>B>>box;
        arr[i]={A, B, box};
    }
    
    sort(arr+1, arr+M+1, comp);
    
    int ans=0;
    for(int i=1; i<=M; i++){
        int start=(get<0>)(arr[i]);
        int end=(get<1>)(arr[i]);
        int box=(get<2>)(arr[i]);

        int maxV=-1, maxIdx=start;
        for(int j=start; j<end; j++){
            if(maeul[j]>maxV){
                maxV=maeul[j];
                maxIdx=j;
            }
        }
        
        if(C-maeul[maxIdx] <= box){
            int temp=C-maeul[maxIdx];
            for(int j=start; j<end; j++){
                maeul[j]+=temp;
            }
            ans+=temp;
        }else{
            for(int j=start; j<end; j++){
                maeul[j]+=box;
            }
            ans+=box;
        }
    }
    
    cout<<ans;
}