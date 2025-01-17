#include <iostream>
#include <string>
using namespace std;

int day[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string ans[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, y;
    cin>>x>>y;
    
    int sum=0;
    for(int i=1; i<x; i++){
        sum+=day[i];
    }
    
    sum+=(y-1);
    cout<<ans[sum%7];
}