#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, J, N, R, C;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        vector<int> v;
        cin>>J>>N;
        for(int i=0; i<N; i++){
            cin>>R>>C;
            v.push_back(R*C);
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        int temp=0;
        for(int i=0; i<N; i++){
            temp+=v[i];
            if(temp>=J){
                cout<<i+1<<"\n";
                break;
            }
        }
        v.clear();
    }
}