#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    string str;
    cin>>N>>K>>str;
    
    for(int i=0; i<N; i++){
        while(!v.empty() && v.back()<str[i] && K>0){
            v.pop_back();
            K--;
        }
        v.push_back(str[i]);
    }
    
    for(int i=0; i<v.size()-K; i++) cout<<v[i];
}