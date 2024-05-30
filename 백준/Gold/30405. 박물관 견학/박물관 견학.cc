#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int K;
        cin>>K;
        for(int j=0; j<K; j++){
            int num;
            cin>>num;
            if(j==0 || j==K-1){
                v.push_back(num);
            }
        }
    }
    
    sort(v.begin(), v.end());
    cout<<v[{v.size()%2==0 ? v.size()/2-1 : v.size()/2}];
}