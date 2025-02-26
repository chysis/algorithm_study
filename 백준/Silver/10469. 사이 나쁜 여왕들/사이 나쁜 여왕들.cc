#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<pair<int, int>> v;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            char c;
            cin>>c;
            if(c=='*') v.push_back({i, j});
        }
    }

    for(int i=0; i<8; i++){
        for(int j=i+1; j<8; j++){
            if((v[i].first==v[j].first) || (v[i].second==v[j].second) || (abs(v[i].first-v[j].first)==abs(v[i].second-v[j].second))){
                cout<<"invalid";
                return 0;
            }
        }
    }
    
    cout<<"valid";
}