#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fib[46];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fib[0]=0;
    fib[1]=1;
    for(int i=2; i<45; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        for(int j=44; j>0; j--){
            if(num>=fib[j]){
                num-=fib[j];
                v.push_back(fib[j]);
            }
        }
        
        sort(v.begin(), v.end());
        for(auto a: v) cout<<a<<" ";
        cout<<"\n";
        
        v.clear();
    }
}