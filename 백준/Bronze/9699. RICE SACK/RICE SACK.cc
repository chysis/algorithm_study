#include <bits/stdc++.h>
using namespace std;

int N, num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        vector<int> v;
        for(int j=0; j<5; j++){
            cin>>num;
            v.push_back(num);
        }
        cout<<"Case #"<<i+1<<": "<<*max_element(v.begin(), v.end())<<"\n";
    }
}