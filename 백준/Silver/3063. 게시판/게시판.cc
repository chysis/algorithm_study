#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int x1, x2, x3, x4, y1, y2, y3, y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        
        int ans=(x2-x1)*(y2-y1);
        ans-=max((min(x2, x4)-max(x1, x3)), 0)*max((min(y2, y4)-max(y1, y3)), 0);
        cout<<ans<<"\n";
    }
}