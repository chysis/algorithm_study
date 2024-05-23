#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    
    for(int i=0; i<M; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for(auto a: v) cout<<a<<" ";
}