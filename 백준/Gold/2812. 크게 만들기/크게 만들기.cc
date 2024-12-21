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
    
    int cnt=0;
    for(int i=0; i<N; i++){
        int cur=str[i]-'0';
        while(!v.empty() && v.back()<cur && cnt<K){
            v.pop_back();
            cnt++;
        }
        v.push_back(cur);
    }
    
    for(int i=0; i<K-cnt; i++) v.pop_back();
    
    for(auto a: v) cout<<a;
}