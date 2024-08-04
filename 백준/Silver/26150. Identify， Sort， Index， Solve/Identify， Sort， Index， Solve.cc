#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<string, int, int> arr[101];

bool comp(tuple<string, int, int>& a, tuple<string, int, int>& b){
    return (get<1>(a))<(get<1>(b));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string s;
        int num, d;
        cin>>s>>num>>d;
        arr[i]={s, num, d};
    }
    
    sort(arr, arr+N, comp);
    
    for(int i=0; i<N; i++){
        char target=get<0>(arr[i])[get<2>(arr[i])-1];

        if('a'<=target && target<='z'){
            cout<<(char)(target-32);
        } else cout<<target;
    }
}