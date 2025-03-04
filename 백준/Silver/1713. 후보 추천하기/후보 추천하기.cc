#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<tuple<int, int, int>> v; // 후보 번호, 투표수, 게시된 시각

bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b){
    if(get<1>(a)!=get<1>(b)) return get<1>(a) > get<1>(b);
    else return get<2>(a) > get<2>(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>T;
    for(int i=0; i<T; i++){
        int num;
        cin>>num;
        auto it=find_if(v.begin(), v.end(), [&num](const tuple<int, int, int>& elem){return get<0>(elem)==num;});
        if(it==v.end()){
            if(v.size()<N){
                v.push_back({num, 1, i});
            } else{
                v.erase(v.begin()+v.size()-1);
                v.push_back({num, 1, i});
            }
        } else{
            get<1>(*it)++;
        }
        
        sort(v.begin(), v.end(), comp);
    }
    
    sort(v.begin(), v.end()); // 번호 순으로 정렬
    for(int i=0; i<v.size(); i++){
        cout<<get<0>(v[i])<<" ";
    }
}