#include <iostream>
#include <algorithm>
#include <tuple>

#define t4i tuple<int, int, int, int>
using namespace std;

t4i arr[100001];

bool comp(t4i& a, t4i& b){
    int sumA=get<1>(a)+get<2>(a)+get<3>(a);
    int sumB=get<1>(b)+get<2>(b)+get<3>(b);
    return sumA>sumB;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, V0, P0, S0;
    cin>>N>>M>>V0>>P0>>S0;
    
    for(int i=0; i<N; i++){
        int V, P, S;
        cin>>V>>P>>S;
        arr[i]={i+1, V, P, S};
    }
    
    sort(arr, arr+N, comp);
    
    cout<<0<<" ";
    
    int cnt=0;
    for(int i=0; i<N; i++){
        if(cnt==M-1) break;
        
        int sum=get<1>(arr[i])+get<2>(arr[i])+get<3>(arr[i]);
        if(sum<=V0+P0+S0){
            cout<<(get<0>(arr[i]))<<" ";
            cnt++;
        }
    }
}