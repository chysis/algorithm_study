#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

tuple<int, int, int> arr[5001];

bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b){
    if(get<0>(a) != get<0>(b)){
        return a<b;
    } else {
        if(get<1>(a) != get<1>(b)){
            return a<b;
        } else {
            return (get<2>(a)) < (get<2>(b));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int A, B, C;
        cin>>A>>B>>C;
        arr[i]={A, B, C};
    }
    
    sort(arr, arr+N, comp);
    
    for(int i=0; i<N; i++){
        cout<<(get<0>(arr[i]))<<" "<<(get<1>(arr[i]))<<" "<<(get<2>(arr[i]))<<"\n";
    }
}