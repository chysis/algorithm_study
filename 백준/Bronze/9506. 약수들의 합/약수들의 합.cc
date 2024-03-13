#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    while(cin>>N){
        if(N==-1) break;
        vector<int> v;
        for(int i=1; i<=N/2; i++){
            if(N%i==0){
                v.push_back(i);
            }
        }
        
        int sum=0;
        for(auto a: v) sum+=a;
        if(sum==N){
            cout<<N<<" = ";
            for(int i=0; i<v.size()-1; i++){
                cout<<v[i]<<" + ";
            }
            cout<<v[v.size()-1]<<"\n";
        }
        else{
            cout<<N<<" is NOT perfect.\n";
        }
    }
}