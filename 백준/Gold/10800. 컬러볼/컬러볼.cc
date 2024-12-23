#include <iostream>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct ColorSize{
    int total=0;
    unordered_map<int, int> um; // 같은 size 아래 color별 개수
};

int ans[200001], sum[200001];
tuple<int, int, int> arr[200001];
ColorSize v[2001];

bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b){
    return get<2>(a) < get<2>(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++){
        int C, S;
        cin>>C>>S;
        arr[i]={i, C, S};
    }
    
    sort(arr, arr+N, comp);
    
    int total=0;
    
    for(int i=0; i<N; i++){
        int curId=get<0>(arr[i]);
        int curColor=get<1>(arr[i]);
        int curSize=get<2>(arr[i]);
        
        int sameColorDiffSizeCnt=v[curSize].total-v[curSize].um[curColor];

        total+=curSize;
        sum[curColor]+=curSize;
        ans[curId]=total-sum[curColor]-sameColorDiffSizeCnt*curSize;
        
        v[curSize].total++;
        if(v[curSize].um.find(curColor)!=v[curSize].um.end()) v[curSize].um[curColor]++;
        else v[curSize].um[curColor]=1;
    }
    
    for(int i=0; i<N; i++) cout<<ans[i]<<"\n";
}