#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    string str;
    cin>>N>>K>>str;
    
    for(int i=0; i<N; i++){
        int cur=str[i]-'0';
        while(!v.empty() && v.back()<cur && K>0){
            v.pop_back();
            K--;
        }
        v.push_back(cur);
    }
    
    for(int i=0; i<v.size()-K; i++) cout<<v[i];
}