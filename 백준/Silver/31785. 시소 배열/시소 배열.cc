#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int Q;
    cin>>Q;
    while(Q--){
        int opt;
        cin>>opt;
        if(opt==1){
            int x;
            cin>>x;
            v.push_back(x);
        } else {
            int sum1=0, sum2=0;
            for(int i=0; i<v.size()/2; i++){
                sum1+=v[i];
            }
            for(int i=v.size()/2; i<v.size(); i++){
                sum2+=v[i];
            }
            
            if(sum1>sum2){
                v.erase(v.begin()+v.size()/2, v.end());
                cout<<sum2<<"\n";
            } else{
                v.erase(v.begin(), v.begin()+v.size()/2);
                cout<<sum1<<"\n";
            }
        }
    }
    
    for(auto a: v){
        cout<<a<<" ";
    }
}