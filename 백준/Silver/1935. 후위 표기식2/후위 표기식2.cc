#include <bits/stdc++.h>
using namespace std;

int N;
string S;
double arr[26], ans=0;
stack<double> s;

bool isNumber(char c){
    // 문제 기준 숫자에 해당
    return c>='A' && c<='Z';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>S;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    for(int i=0; i<S.length(); i++){
        if(isNumber(S[i])){
            s.push(arr[S[i]-'A']);
        }else{
            double second=s.top();
            s.pop();
            double first=s.top();
            s.pop();
            double temp;
            
            if(S[i]=='+') temp=first+second;
            else if(S[i]=='-') temp=first-second;
            else if(S[i]=='*') temp=first*second;
            else if(S[i]=='/') temp=first/second;
            
            s.push(temp);
        }
    }
    
    cout<<fixed;
    cout.precision(2);
    
    cout<<s.top();
}