#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K, newK, dig;
    cin>>K;
    
    for(int i=1; ; i++){
        if(pow(2, i)-2<K && pow(2, i+1)-2>=K) {
            dig=i;
            break;
        }
    }
    
    newK=K-pow(2, dig)+1;

    vector<int> v;
    while(newK>0){
        v.push_back(newK%2);
        newK/=2;
    }
    
    string ans(dig, '4');
    
    for(int i=0; i<v.size(); i++){
        ans[dig-i-1]=(v[i]==0?'4':'7');
    }
    
    cout<<ans;
}