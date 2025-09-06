#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

string N;
int minAns=INF, maxAns=-1;

int countOdd(string str){
    int cnt=0;
    for(int i=0; i<str.length(); i++){
        if((str[i]-'0')%2==1) cnt++;
    }
    return cnt;
}

void solve(string str, int cnt){
    if(str.length()==1){
        minAns=min(minAns, cnt+(stoi(str)%2==1 ? 1 : 0));
        maxAns=max(maxAns, cnt+(stoi(str)%2==1 ? 1 : 0));
        return;
    }else if(str.length()==2){
        string newStr=to_string(stoi(str.substr(0, 1))+stoi(str.substr(1, 1)));
        solve(newStr, cnt+countOdd(str));
    }else{
        for(int i=1; i<str.length()-1; i++){
            for(int j=i+1; j<str.length(); j++){
                string one=str.substr(0, i);
                string two=str.substr(i, j-i);
                string three=str.substr(j);
                string newStr=to_string(stoi(one)+stoi(two)+stoi(three));
                solve(newStr, cnt+countOdd(str));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    solve(N, 0);
    cout<<minAns<<" "<<maxAns;
}