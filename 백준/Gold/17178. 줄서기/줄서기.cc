#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

deque<string> w, v, sorted;

bool comp(string& a, string& b){
    if(a[0]!=b[0]){
        return a<b;
    } else{
        return stoi(a.substr(2))<stoi(b.substr(2));
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0; i<5*N; i++){
        string str;
        cin>>str;
        v.push_back(str);
        sorted.push_back(str);
    }
    
    sort(sorted.begin(), sorted.end(), comp);
    
    int now=0;
    while(true){
        if(v.empty() && w.empty()) break;
        string wFront=w.empty() ? "-1" : w.front();
        string vFront=v.empty() ? "-1" : v.front();
        
        // cout<<wFront<<" "<<vFront<<"\n";
        
        if(sorted[now]!=wFront && vFront=="-1") break;
        // if(sorted[now]!=vFront && wFront=="-1") break;
        
        if(sorted[now]==wFront){
            now++;
            w.pop_front();
        } else if(sorted[now]==vFront){
            now++;
            v.pop_front();
        } else{
            string temp=v.front();
            v.pop_front();
            w.push_front(temp);
        }
    }
    
    if(now==5*N) cout<<"GOOD";
    else cout<<"BAD";
}