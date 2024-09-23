#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int o=0, t=0;
    for(int i=0; i<3; i++){
        int num;
        cin>>num;
        if(num==1) o++;
        else t++;
    }
    
    if(o>t) cout<<1;
    else cout<<2;
}