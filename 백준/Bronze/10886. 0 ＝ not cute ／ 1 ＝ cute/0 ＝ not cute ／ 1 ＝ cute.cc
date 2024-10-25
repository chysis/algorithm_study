#include <iostream>
using namespace std;

int zero=0, one=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        if(num==1) one++;
        else zero++;
    }
    
    if(one>zero) cout<<"Junhee is cute!";
    else cout<<"Junhee is not cute!";
}