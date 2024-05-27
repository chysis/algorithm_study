#include <iostream>
#include <cmath>
#define MOD 1234567891
using namespace std;

int main(){
    char c;
    int ans=0;
    int L;
    cin>>L;
    for(int i=0; i<L; i++){
        cin>>c;
        long long temp=c-'a'+1;
        int cnt=i;
        while(cnt--){
            temp=(temp*31)%MOD;
        }
        ans=(ans+temp)%MOD;
    }
    cout<<ans;
}