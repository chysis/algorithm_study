#include <bits/stdc++.h>
using namespace std;

int N, M;
char R, C;
vector<char> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true){
        cin>>R>>N>>C>>M;
        if(N==0 && M==0) break;
        
        while(M>0){
            if(M%26==0) {
                v.push_back('Z');
                M=M/26-1;
            } else{
                v.push_back(M%26-1+'A');
                M/=26;
            }
        }
        
        reverse(v.begin(), v.end());
        for(auto a: v) cout<<a;
        cout<<N<<"\n";
        
        v.clear();
    }
}