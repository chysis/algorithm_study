#include <bits/stdc++.h>
using namespace std;

int ans;
string A, B, C;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>A>>B>>C;
    if(A!="Fizz" && A!="Buzz" && A!="FizzBuzz") ans=stoi(A)+3;
    else if(B!="Fizz" && B!="Buzz" && B!="FizzBuzz") ans=stoi(B)+2;
    else if(C!="Fizz" && C!="Buzz" && C!="FizzBuzz") ans=stoi(C)+1;
    
    if(ans%15==0) cout<<"FizzBuzz";
    else if(ans%5==0) cout<<"Buzz";
    else if(ans%3==0) cout<<"Fizz";
    else cout<<ans;
}