#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long
using namespace std;

pair<int, ll> score[10];
bool isFirst[10];

bool comp(pair<int, ll>& a, pair<int, ll>& b){
    if(a.second!=b.second) return a.second>b.second;
    else return a.first<b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    for(int i=0; i<10; i++){
        score[i]={i, 0};
    }
    
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        for(int j=0; j<str.length(); j++){
            score[str[j]-'A'].second+=pow(10, str.length()-j-1);
            if(j==0) isFirst[str[j]-'A']=true;
        }
    }
    
    sort(score, score+10, comp);
    
    
    if(isFirst[score[9].first]){
        for(int i=8; i>=0; i--){
            if(!isFirst[score[i].first]){
                swap(score[i], score[9]);
                break;
            }
        }
    }
    
    sort(score, score+9, comp);
    
    int num=9;
    ll ans=0;
    for(int i=0; i<10; i++){
        ans+=score[i].second*num--;
    }
    
    cout<<ans;
}