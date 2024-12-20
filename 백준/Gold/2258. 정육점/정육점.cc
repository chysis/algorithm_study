#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> meat[100001];

bool comp(pair<int, int>& a, pair<int, int>& b){
    if(a.second!=b.second) return a.second<b.second;
    else return a.first>b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int W, P;
        cin>>W>>P;
        meat[i]={W, P};
    }
    
    sort(meat, meat+N, comp);
    
    int sumWeight=0, sumPrice=0, tempPrice=0;
    for(int i=0; i<N; i++){
        if(sumWeight<M){
            if(meat[i].second!=tempPrice){
                sumWeight+=meat[i].first;
                sumPrice=meat[i].second;
                tempPrice=meat[i].second;
            }else{
                sumWeight+=meat[i].first;
                sumPrice+=meat[i].second;
            }
        }else{
            if(meat[i].second!=tempPrice && sumPrice>meat[i].first){
                sumPrice=min(sumPrice, meat[i].second);
            }
        }
    }
    
    if(sumWeight>=M) cout<<sumPrice;
    else cout<<-1;
}